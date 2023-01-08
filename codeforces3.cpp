    #include <iostream>
    #include <vector>
     
    void printContents(std::vector<std::vector<bool>>& box, int& rows, int& coloumns)
    {
    	
    	for (int i = 0; i < rows; i++)
    	{
    		for (int x = 0; x < coloumns; x++)
    		{
    			std::cout << box[i][x] << " ";
    		}
    		std::cout << std::endl;
    	}
    }
    int main()
    {
     
    	int coloumns, x;
    	std::cin >> coloumns;
    	std::vector<int> checkList;
    	bool greatest;
    	int rows;
    	for (int i = 0; i < coloumns; i++)
    	{
    		std::cin >> x;
    		checkList.push_back(x);
     
     
    		if (i == coloumns - 1)
    		{
    			for (size_t X = 0; X < checkList.size(); X++)
    			{
     
    				for (size_t w = 0; w < checkList.size(); w++)
    				{
    					if (checkList[X] >= checkList[w])
    					{ 
    						greatest = 1;
    						continue;
    					}
    					else
    					{ 
    						greatest = 0;
    						break;
    					}
    				}
     
    				if (greatest)
    				{
    					rows = checkList[X];
    					break;
    				}
    			}
    		}
    	}
    	
    	std::vector<std::vector<bool>> box(rows);
    	std::vector<bool> vec(coloumns);
     
    	for (int i = 0; i < rows; i++)
    	{
    		box[i] = vec;
     
    		for (int l = 0; l < coloumns; l++)
    		{
    			box[i][l] = (bool)0;
    		}
    	}
     
    	int index = 0;
    	int secondIndex = 0;
    	int i = rows - 1;
     
    	while (1)
    	{
     
    		for (int w = 0; w < checkList[secondIndex]; w++)
    		{
    			box[i][index] = 1;
    			i--;
    		}
     
    		index++;
    		i = rows - 1;
    		secondIndex++;
    		if (secondIndex == coloumns)
    			break;
    	}
     
    	int currentPosition;
    	int ones = 0;
    	bool temp;
    	
    	for (int i = 0; i < rows; i++)
    	{
     
     
    		for (int x = 0; x < coloumns; x++)
    		{
    			if (box[i][x] == 0 && x != 0)
    			{
    				currentPosition = x;
    				for (int a = x - 1; a < coloumns; a++)
    				{
    					if (box[i][a] == 1)
    					{
    						temp = box[i][a];
    						box[i][a] = box[i][currentPosition];
    						box[i][currentPosition] = temp;
    						break;
    					}
    				}
    			}
     
    			else
    			{
    				currentPosition = x;
     
    				for (int a = x + 1; a < coloumns; a++)
    				{
    					if (box[i][a] == 0)
    					{
    						temp = box[i][a];
    						box[i][a] = box[i][currentPosition];
    						box[i][currentPosition] = temp;
    						x = 0;
    						break;
    					}
     
    					else
    					{ 
    						break;
    					}
    				}
    			}
    		}
    	}
    	
     
    	index = 0;
    	secondIndex = 0;
    	i = rows - 1;
    	int howMany = 0;
    	while (1)
    	{
     
    		for (int w = 0; w < rows; w++)
    		{
    			if (box[i][index] == 1)
    			{ 
    				i--;
    				howMany++;
    			}
    		}
    		std::cout << howMany << " ";
    		howMany = 0;
    		index++;
    		i = rows - 1;
    		secondIndex++;
    		if (secondIndex == coloumns)
    			break;
    	}
    	
    }
