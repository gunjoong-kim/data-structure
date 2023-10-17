#pragma once
#ifndef INTMAXHEAP_HPP
#define INTMAXHEAP_HPP

#define DEFAULT_SIZE 100

class IntMaxHeap
{
	private:
		size_t m_size;
		size_t m_arm;
		int* m_arr;
	public:
		IntMaxHeap();
		IntMaxHeap(int arr[]);
		IntMaxHeap(const IntMaxHeap& h);
		~IntMaxHeap();
		void insert(int priority);
		int remove();
		int get_first();
};

#endif