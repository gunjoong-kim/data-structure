#include "IntMaxHeap.hpp"

IntMaxHeap::IntMaxHeap()
{
	this->m_size = DEFAULT_SIZE;
	this->m_arr = new int[this->m_size];
	this->m_arm = 0;
}

IntMaxHeap::IntMaxHeap(int arr[], size_t len)
{
	//size 정확하게 입력해야 동작함
	if (DEFAULT_SIZE < len)
		this->m_size = len;
	else
		this->m_size = DEFAULT_SIZE;
	this->m_arr = new int[this->m_size];
	this->m_arm = 0;
	for (int i = 0; i < len; i++)
	{
		this->insert(arr[i]);
	}
}

IntMaxHeap::IntMaxHeap(const IntMaxHeap& h)
{
	this->m_size = h.m_size;
	this->m_arm = h.m_arm;
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

IntMaxHeap& IntMaxHeap::operator=(const IntMaxHeap& h)
{
	if (this == &h)
		return *this;

	if (this->m_size < h.m_size)
	{
		this->m_size = h.m_size;
		delete this->m_arr;
		this->m_arr = new int[this->m_size];
	}
	this->m_arm = h.m_arm;
	for (int i = 0; i < h.m_arm; i++)
	{
		this->m_arr[i] = h.m_arr[i];
	}
	return *this;
}

void IntMaxHeap::insert(int priority)
{
	//만약 이미 내부 배열이 꽉 찼다면 두배만큼 재할당
	// m_arm 위치에 값집어넣기
	// 위치가 0이 되거나 부모가 자신보다 작을 때까지 up heap
	if (this->m_arm == this->m_size)
	{
		int *new_arr = new int[this->m_size * 2];
		for (int i = 0; i < this->m_size; i++)
			new_arr[i] = this->m_arr[i];
		delete this->m_arr;
		m_arr = new_arr;
		this->m_size *= 2;
	}

	size_t target = m_arm;
	size_t parent;
	this->m_arr[target] = priority;
	while (1)
	{
		if (target == 0)
			break ;
		parent = (target - 1) / 2;
		if (this->m_arr[parent] < priority)
		{
			int tmp = m_arr[target];
			m_arr[target] = m_arr[parent];
			m_arr[parent] = tmp;
		}
		else
			break ;
		target = parent;
	}
	(this->m_arm)++;
}

void IntMaxHeap::remove()
{
	if (this->is_empty())
	{
		std::cout << "Heap is Empty...\n";
		return ;
	}

	this->m_arr[0] = this->m_arr[m_arm - 1];
	(this->m_arm)--;
	int left, right, max;

	int k = 0;
	while (1)
	{
		left = 2 * k + 1;
		right = 2 * k + 2;
		if (left >= m_arm && right >= m_arm)
			break ;
		else if (left >= m_arm)
		{
			if (this->m_arr[right] > this->m_arr[k])
			{
				std::swap(this->m_arr[right], this->m_arr[k]);
				k = right;
			}
			else
				break ;
		}
		else if (right >= m_arm)
		{
			if (this->m_arr[left] > this->m_arr[k])
			{
				std::swap(this->m_arr[left], this->m_arr[k]);
				k = left;
			}
			else
				break ;
		}
		else
		{
			max = left;
			if (this->m_arr[left] < this->m_arr[right])
				max = right;
			if (this->m_arr[max] > this->m_arr[k])
			{
				std::swap(this->m_arr[max], this->m_arr[k]);
				k = max;
			}
			else
				break ;
		}
	}
}

int IntMaxHeap::top()
{
	return this->m_arr[0];
}

void IntMaxHeap::clear()
{
	this->m_arm = 0;
}

bool IntMaxHeap::is_empty()
{
	if (this->m_arm == 0)
		return true;
	else
		return false;
}

void IntMaxHeap::print()
{
	if (this->is_empty())
	{
		std::cout << "Heap is empty...\n";
		return ;
	}
	std::cout << "Print Heap\n";
	for (int i = 0; i < this->m_arm; i++)
	{
		std::cout << this->m_arr[i] << ' ';
	}
	std::cout << "end...\n";
}