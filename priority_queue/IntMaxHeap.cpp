#include "IntMaxHeap.hpp"

IntMaxHeap::IntMaxHeap()
{
	this->m_size = DEFAULT_SIZE;
	this->m_arr = new int[this->m_size];
	this->m_arm = 0;
}

IntMaxHeap::IntMaxHeap(int arr[])
{
	this->m_size = sizeof(arr) / sizeof(int) * 2;
	this->m_arr = new int[this->m_size];
	//heapify
}

IntMaxHeap::IntMaxHeap(const IntMaxHeap& h)
{
	this->m_size = h.m_size;
	this->m_arr = new int[this->m_size];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_arr[i] = h.m_arr[i];
	}
}

IntMaxHeap::~IntMaxHeap()
{
	delete m_arr;
}

void IntMaxHeap::insert(int priority)
{

}

int IntMaxHeap::remove()
{

}

int IntMaxHeap::get_first()
{

}