/*
 * bubble_sort.c
 *
 *  Created on: Jan 12, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char c;
	struct node* next;
};

// bubble sort
void bubble_sort(struct node* head, int num_nodes)
{
	char swap_val = ' ';

    // validate input
	if (NULL == head) return;

	// bubble sort
	for (int i=0; i<num_nodes-1; i++)
	{
		for (struct node* curr = head; curr != NULL && curr->next != NULL; curr = curr->next)
		{
			if (curr->c > curr->next->c)
			{
				// swap values
				swap_val = curr->next->c;
				curr->next->c = curr->c;
				curr->c = swap_val;
			}
		}

		printf("\nafter iter: ");

		// print out char seq of list after each iter
		for (struct node* n = head; n != NULL; n = n->next)
		{
			printf("%c ", n->c);
		}
	}
}

void print_arr(char* arr, int size_arr)
{
	// sanity check contents of arr
	for (int i=0; i<size_arr; i++)
		printf(" %c ", arr[i]);
}

void merge(char* la, char* ra, char* out_da, int size_a)
{
	// compare the least of the left
	// with the highest of the right
	// next compare the least of right
	// with least of left
	if (la[0] > ra[size_a-1])
	{
		printf("\nright first, then left, size_a:%d", size_a);
		memcpy(out_da, ra, size_a);
		memcpy(&out_da[size_a], la, size_a);
	}
	else if (la[size_a-1] < ra[0])
	{
		printf("\nleft first, then right");
		memcpy(out_da, la, size_a);
		memcpy(&out_da[size_a], ra, size_a);
	}
	else
	{
		int i=0, j=0, k=0;

		printf("\n else case in merge");
		while (i<size_a && j<size_a)
		{
			for (; (i<size_a) && (la[i] < ra[j]); i++)
			{
				printf("\nla");
				out_da[k++] = la[i];
			}

			for (; (j<size_a) && (ra[j] < la[i]); j++)
			{
				printf("\nra");
				out_da[k++] = ra[j];
			}
			printf("\ni:%d, j:%d", i, j);
		}

		// copy any leftovers
		if (i < size_a)
		{
			memcpy(&out_da[k], &la[i], size_a - i);
		}
		else if (j < size_a)
		{
			memcpy(&out_da[k], &ra[j], size_a - j);
		}
	}
}

void mergesort(char* arr, char* out_a, int size_a)
{
    if (1 == size_a)
    {
    	memcpy(out_a, arr, 1);
    	return;
    }

    char la[size_a/2];
    char ra[size_a/2];

    // split into half : left, right
    for (int ix = 0, lix = 0, rix = 0; ix < size_a && rix < size_a/2; ix++)
    {
		if (ix < size_a/2) // left array
		{
			la[lix++] = arr[ix];
		}
		else // right array
		{
			ra[rix++] = arr[ix];
		}
    }

    mergesort(la, out_a, size_a/2);
    memcpy(la, out_a, size_a/2);
    mergesort(ra, out_a, size_a/2);
    memcpy(ra, out_a, size_a/2);

    printf("\nLeft array:");
    print_arr(la, size_a/2);
    printf("\nRight array:");
    print_arr(ra, size_a/2);

    // sort and merge resulting la, ra into out_a
    memset(out_a, 0, size_a);
    merge(la, ra, out_a, size_a/2);

    printf("\nDest array:");
    print_arr(out_a, 8);
}


// Description: split list into halves and sort up
void merge_sort(struct node* head, int num_nodes)
{
	int i=0;
	// get the data into array
	char arr[num_nodes];
	// output array
	char out_arr[num_nodes];
	memset(out_arr, 0, num_nodes);

	for (struct node* n = head; n != NULL; n = n->next)
	{
		arr[i++] = n->c;
	}

	mergesort(arr, out_arr, num_nodes);

	printf("\nFinal out arr:");
	print_arr(out_arr, num_nodes);
}


int main()
{
	// populate the linked list
    struct node *head, *ll;
    ll = (struct node*) calloc (1, sizeof(struct node));
    head = ll;
    ll->c = 'z';
    ll->next = (struct node*) calloc (1, sizeof(struct node));
    ll = ll->next;
    ll->c = 'y';
    ll->next = (struct node*) calloc (1, sizeof(struct node));
    ll = ll->next;
    ll->c = 'x';
    ll->next = (struct node*) calloc (1, sizeof(struct node));
    ll = ll->next;
    ll->c = 'c';
    ll->next = (struct node*) calloc (1, sizeof(struct node));
    ll = ll->next;
    ll->c = 'b';
    ll->next = (struct node*) calloc (1, sizeof(struct node));
    ll = ll->next;
    ll->c = 'a';
    ll->next = (struct node*) calloc (1, sizeof(struct node));
    ll = ll->next;
    ll->c = 'p';
    ll->next = (struct node*) calloc (1, sizeof(struct node));
    ll = ll->next;
    ll->c = 'q';
    ll->next = NULL;


    // bubble sort
    // bubble_sort(head, 6);

    // merge sort
    merge_sort(head, 8);

    // quick sort
    //quick_sort(head);

    // bucket sort
    //bucket_sort(head);
}
