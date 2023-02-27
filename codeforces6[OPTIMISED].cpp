    #include <iostream>
    #include <vector>
     
     
    class Wire
    {
    private:
    	int m_Birds;
     
    public:
     
    	std::vector<bool> occupied;
     
    	Wire(int& birds)
    		: m_Birds(birds)
    	{
    		this->occupied.reserve(this->m_Birds);
     
    		for (int i = 0; i < m_Birds; i++)
    			occupied.emplace_back(1);
    	}
    	
    	Wire(const Wire& already)
    	{
    		memcpy(this, &already, sizeof(Wire));
    		std::cout << "Copied" << '\n';
    	}
     
    	friend void TakeOut(std::vector<Wire>& container, int& x, int& y);
    };
     
     
    void TakeOut(std::vector<Wire>& container, int& x, int& y)
    {
    	x--;
     
     
    	if (x > 0 && x < container.size() - 1)
    	{ 
    		for (int i = 0; i < y; i++)
    		{
    			container[x].occupied.erase(container[x].occupied.begin());
    			
    		}
     
    		for (int i = 0; i < y - 1; i++)
    			container[x - 1].occupied.emplace_back(1);
     
    		const size_t size = container[x].occupied.size();
     
    		for (int i = 0; i < size; i++)
    		{
    			container[x].occupied.erase(container[x].occupied.begin());
    			container[x + 1].occupied.emplace_back(1);
    		}
     
    	}
     
    	else if (x == 0 && x != container.size() - 1)
    	{
    		for (int i = 0; i < y; i++)
    		{
    			container[x].occupied.erase(container[x].occupied.begin());
    		}
     
    		const size_t size = container[x].occupied.size();
     
    		for (int i = 0; i < size; i++)
    		{
    			container[x].occupied.erase(container[x].occupied.begin());
    			container[x + 1].occupied.emplace_back(1);
    		}
     
    	}
     
    	else if (x == container.size() - 1)
    	{
    		for (int i = 0; i < y; i++)
    		{
    			container[x].occupied.erase(container[x].occupied.begin());
    		}
     
    		for (int i = 0; i < y - 1 && container.size() != 1; i++)
    			container[x - 1].occupied.emplace_back(1);
     
    		const size_t size = container[x].occupied.size();
     
    		for (int i = 0; i < size; i++)
    		{
    			container[x].occupied.erase(container[x].occupied.begin());
    		}
     
    	}
     
    }
     
    int main()
    {
     
    	int WiresNshots;
     
    	int birds;
     
    	int x, y;
     
    	std::vector<Wire> paralelled;
     
    	std::cin >> WiresNshots;
     
    	paralelled.reserve(WiresNshots);
     
    	for (int i = 0; i < WiresNshots; i++)
    	{
     
    		std::cin >> birds;
     
    		paralelled.emplace_back(birds);
     
    	}
     
    	std::cin >> WiresNshots;
     
    	for (int i = 0; i < WiresNshots; i++)
    	{
    		std::cin >> x >> y;
     
    		TakeOut(paralelled, x, y);
    	}
     
    	for (int i = 0; i < paralelled.size(); i++)
    		std::cout << paralelled[i].occupied.size() << '\n';
     
    }
