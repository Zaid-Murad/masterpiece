#include <iostream>

template<typename T>
class DynamicArray
{

private:
	size_t m_Size;
	size_t m_Capacity;
	T* m_Buffer;
	std::allocator<T> allocator;

private:
	void ReAlloc(size_t new_Size, size_t& old_Capacity) // The new reallocation has +1 slot.
	{
		T* BiggerBuffer = allocator.allocate(new_Size);

		for (int i = 0; i < old_Capacity; i++)
			std::construct_at(BiggerBuffer + i, std::move(m_Buffer[i]));

		for (int i = 0; i < old_Capacity; i++)
			std::destroy_at(&m_Buffer[i]);

		allocator.deallocate(m_Buffer, old_Capacity);

		m_Buffer = BiggerBuffer;

		BiggerBuffer = nullptr;

		old_Capacity++;
	}

public:

	DynamicArray() // default constructor
		: m_Size(NULL), m_Capacity(NULL), m_Buffer(nullptr)
	{

	}

	DynamicArray(DynamicArray&&) = delete; // Move Constructor

	DynamicArray(const DynamicArray& already) = delete; // Copy Constructor

	DynamicArray& operator=(const DynamicArray&) = delete; // Copy Assignment Operator

	DynamicArray& operator=(DynamicArray&&) = delete; // Move Assignment Operator

	// lvalue overload
	void PushBack(T& element) 
	{

		m_Size++;

		if (m_Size <= m_Capacity)
			std::construct_at(m_Buffer + (m_Size - 1), std::move(element)); // 

		else
		{

			ReAlloc(m_Size, m_Capacity);
			
			std::construct_at(m_Buffer + (m_Size - 1), std::move(element));

		}
	}

	// rvalue overload
	void PushBack(T&& element) //The same body. I dont want to copy if moving is possible.
	{
		m_Size++;

		if (m_Size <= m_Capacity)
			std::construct_at(m_Buffer + (m_Size - 1), std::move(element));

		else
		{

			ReAlloc(m_Size, m_Capacity);

			std::construct_at(m_Buffer + (m_Size - 1), std::move(element));
		}
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		m_Size++;

		if (m_Size <= m_Capacity)
		{ 
			std::construct_at(m_Buffer + (m_Size - 1), std::forward<Args>(args)...);

			return m_Buffer[m_Size - 1];
		}

		else
		{

			ReAlloc(m_Size, m_Capacity);
			std::construct_at(m_Buffer + (m_Size - 1), std::forward<Args>(args)...);

			return m_Buffer[m_Size - 1];
		}
	}

	size_t size()
	{
		return m_Size;
	}

	T& operator[](int index)
	{
		return m_Buffer[index];
	}

	~DynamicArray()
	{
		for (int i = 0; i < m_Size; i++)
			std::destroy_at(&m_Buffer[i]);

		allocator.deallocate(m_Buffer, m_Capacity);

		m_Size = NULL;

		m_Capacity = NULL;
	}

};


class String
{
private:
	size_t m_Size = NULL;
	char* m_Buffer = nullptr;

public:
	
	String() = default;

	String(const char* data) // Constructed with a string literal
		: m_Size(strlen(data)), m_Buffer(new char[m_Size + 1])
	{

		memcpy(m_Buffer, data, m_Size + 1);
		m_Buffer[m_Size] = 0;
	}

	String(String&& already) noexcept // Moving an old string to a new one.
		: m_Size(already.m_Size), m_Buffer(already.m_Buffer)
	{


		already.m_Buffer = nullptr;

		std::destroy_at(&already);

	}
	
	String(const String& already) // copying an old string into a new one.
		: m_Size(already.m_Size), m_Buffer(new char[m_Size + 1])
	{

		memcpy(this->m_Buffer, already.m_Buffer, m_Size + 1);

	}

	String& operator=(const String& already) // Copying an old string into an old one.
	{

		if (this != &already)
		{
			m_Size = already.m_Size;
			m_Buffer = new char[m_Size + 1];
			memcpy(this->m_Buffer, already.m_Buffer, m_Size + 1);

		}

		return *this;
	}

	String& operator=(String&& already) noexcept // Moving an old string to an old one.
	{
		if (this != &already)
		{
			m_Size = already.m_Size;
			m_Buffer = already.m_Buffer;

			already.m_Buffer = nullptr;

			std::destroy_at(&already);
		}

		return *this;
	}

	~String()
	{
		delete[] m_Buffer;
	
		m_Size = 0;
	}

	friend std::ostream& operator<<(std::ostream& stream, String& string);

};


std::ostream& operator<<(std::ostream& stream, String& string)
{
	stream << string.m_Buffer;
	return stream;
}

int main()
{

	DynamicArray<String> vector;

	String name = "Zaid";

	vector.PushBack(name);

	vector.EmplaceBack("A7a");

	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
}
