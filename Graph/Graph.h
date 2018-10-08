#pragma once
#include <iostream>
#include "DLL.h"
#include <vector>
#include <string>

class Graph
{
private:
	std::vector<DblyLinkedList<std::string>*> map; //map structure; holds vector of DLL pointers for ease of access
    DblyLinkedList<std::string> *local; //DLL pointer to point to DLL in vector ->map
    //std::vector<T> visited;//use to check if location in ->map has been visited, only holds data that can be found in DLL ->data
    std::vector<std::string> names;
    int size;
    std::vector<bool> visit;
    void init(int size)
    {
        for (int i = 0; i < size; i++)
        {
            this->map.push_back(new DblyLinkedList<std::string>);
            //this->map[i]->vertex;
        }
    }
public:
    Graph(int size)
    {
        this->size = size;
        this->init(size);
    }
	void addEdge(std::string src, std::string des)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->local = this->map[i];
			if (this->local->getHead() == NULL)
			{
                this->names.push_back(src);
                this->visit.push_back(false);
				this->local->addEnd(src);
				this->local->addEnd(des);
				break;
			}
			else if (this->local->getHeadData() == src)
			{
				this->local->addEnd(des);
				break;
			}
		}
	}
    void delEdge(std::string src)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->map[i]->getHeadData() == src)
            {
                this->map.erase(this->map.begin() + i);
                break;
            }
           
        }
        this->size--;
    }
    void delDes(std::string src, std::string des)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->map[i]->getHeadData() == src)
                this->map[i]->del(des);
        }
    }
	void depthFirstTrav(int index)
	{
		std::cout << index << ".\t" << names[index] << std::endl;
        node<std::string> *p = this->map[index]->getHead();
		this->visit[index] = true;
		while (p != NULL)
		{
            for (int i = 0; i < this->size; i++)
            {
                if (p->data == this->map[i]->getHeadData())
                {
                    index = i;
                    break;
                }
            }
            if (!this->visit[index])
                this->depthFirstTrav(index);
			p = p->next;
		}
	}
    
	void printGraph()
	{
		for (int i = 0; i < this->size; i++)
		{
            std::cout << i << ". "; this->map[i]->print();
		}
	}
};