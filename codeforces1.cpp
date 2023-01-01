    #include <iostream>
    #include <random>
    #include <string>
    #include <vector>
     
    int digits(int copy)
    {
    	int fact = 1;
    	int counter = 0;
    	while (1)
    	{
    		copy /= fact;
    		if (copy == 0)
    		{
    			counter++;
    			return counter;
    		}
     
    		else
    			counter++;
     
    		fact *= 10;
    	}
     
    }
     
    bool first(bool& firstStage, int copy)
    {
     
    	if (copy % 4 == 0 || copy % 7 == 0)
    	{
    		firstStage = 1;
    		return firstStage;
    	}
     
    	else
    	{
    		int fact = 1;
    		int count = 0;
    		int i = digits(copy);
    		while (count < i)
    		{
    			copy /= fact;
     
    			if (copy % 10 == 4 || copy % 10 == 7)
    				firstStage = 1;
     
    			else
    			{
    				firstStage = 0;
    				return firstStage;
    			}
     
    			fact *= 10;
    			count++;
    		}
     
    		return firstStage;
    	}
    }
     
    int power(int base, int iterations)
    {
    	for (int i = 0; i < iterations - 1; i++)
    	{
    		base *= 2;
    	}
     
    	return base;
    }
    int main()
    {
    	bool firstStage;
    	int number;
     
    	std::cin >> number;
     
    	if (first(firstStage, number))
    	{ 
    		std::cout << "YES" << std::endl;
    		return 0;
    	}
    	else
    	{
     
    		std::string incomingINT;
     
    		int possible = power(2, digits(number));
    		// std::cout << possible << std::endl;
    		int counter = digits(number);
    		// int innerCounter = digits(number);
     
    		std::vector<int> permutations;
     
    		char array[3] = { '4', '7', 0 };
    		int size;
    		int flip;
    		std::random_device rd;
    		std::uniform_int_distribution<int> dist(0, 1);
     
    		
    		while (counter > 1)
    		{
    			size = 0;
    			while (1)
    			{
    				if (size == possible)
    					break;
     
    				flip = dist(rd);
    				bool found = 0;
    				incomingINT += array[flip];
     
    				if (incomingINT.size() == counter)
    				{
    					int temp = std::stoi(incomingINT);
     
    					for (int x = 0; x < permutations.size(); x++)
    					{
    						if (temp == permutations[x])
    						{
    							found = 1;
    							break;
    						}
    					}
     
    					if (found)
    					{
    						found = 0;
    						incomingINT.clear();
    						continue;
    					}
     
    					else
    					{
    						int temp = std::stoi(incomingINT);
    						permutations.push_back(temp);
    						size++;
    						incomingINT.clear();
    					}
    				}
    			}
    			counter--;
    			possible = power(2, counter);
    		}
     
     
    		for (int i = 0; i < permutations.size(); i++)
    		{
    			if (number % permutations[i] == 0)
    			{
    				std::cout << "YES" << std::endl;
    				return 0;
    			}
    		}
    	}
     
    	std::cout << "NO" << std::endl;
    }
