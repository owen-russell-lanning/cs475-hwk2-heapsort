/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{

	buildHeap(A, n);

	
	// for(int i = n; i > 0; i--){
	// 	swap(&A[i-1], &A[0]);
	// 	heapify(A, i-1,n);
	// }
	while(n > 0){
		swap(&A[n-1], &A[0]);
		n--;
		heapify(A, 0, n);
	}

	// TODO - while n > 0:
	// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
	// TODO - A[n-1] now sorted in place, so decrement n
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{

	for(int i = n/2; i>=0; i--){
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{

	// get the left and right children
	int leftChildIndex = (2 * (i + 1)) - 1;
	int rightChildIndex = 2 * (i + 1);
	if (leftChildIndex > (n - 1) && rightChildIndex > (n - 1))
	{
		return; // canot go any further in the heap
	}

	// determine smaller salary
	Employee smaller;
	int smallerIndex;
	if (rightChildIndex > (n - 1)) // see if right child is out of bounds. if so left index is chosen. don't check for left child as that is included in the above check
	{
		smaller = A[leftChildIndex];
		smallerIndex = leftChildIndex;
	}
	else
	{

		// otherwise compare two children for smallest
		Employee leftChild = A[leftChildIndex];
		Employee rightChild = A[rightChildIndex];
		if (leftChild.salary > rightChild.salary)
		{
			smaller = rightChild;
			smallerIndex = rightChildIndex;
		}
		else
		{
			smaller = leftChild;
			smallerIndex = leftChildIndex;
		}
	}

	// if smaller, move
	if (A[i].salary > smaller.salary)
	{
		// swap and recur
		swap(&A[smallerIndex], &A[i]);

		
		heapify(A, smallerIndex, n);
	}


}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		Employee e = A[i];
		printf("Salary: %d, Name: %s\n", e.salary, e.name);
	}
}



