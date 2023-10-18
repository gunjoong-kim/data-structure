#pragma once
#ifndef INTMAXHEAP_HPP
#define INTMAXHEAP_HPP

#include <iostream>
#include <stddef.h>

#define DEFAULT_SIZE 3

class IntMaxHeap
{
	private:
		size_t m_size;
		size_t m_arm;
		int* m_arr;
	public:
		IntMaxHeap();
		IntMaxHeap(int arr[], size_t len);
		IntMaxHeap(const IntMaxHeap& h);
		~IntMaxHeap();
		IntMaxHeap& operator=(const IntMaxHeap& h);
		void insert(int priority);
		void remove();
		int top();
		void clear();
		bool is_empty();
		void print();
};

#endif