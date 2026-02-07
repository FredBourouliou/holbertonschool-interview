#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;

	/* Test 1: Empty list (palindrome) */
	head = NULL;
	if (is_palindrome(&head) == 1)
		printf("Test 1 PASS: Empty list is a palindrome\n");
	else
		printf("Test 1 FAIL: Empty list should be a palindrome\n");

	/* Test 2: Single element (palindrome) */
	add_nodeint_end(&head, 1);
	if (is_palindrome(&head) == 1)
		printf("Test 2 PASS: Single element is a palindrome\n");
	else
		printf("Test 2 FAIL: Single element should be a palindrome\n");
	free_listint(head);

	/* Test 3: Two same elements (palindrome) */
	head = NULL;
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 2);
	if (is_palindrome(&head) == 1)
		printf("Test 3 PASS: [2,2] is a palindrome\n");
	else
		printf("Test 3 FAIL: [2,2] should be a palindrome\n");
	free_listint(head);

	/* Test 4: Two different elements (not palindrome) */
	head = NULL;
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 3);
	if (is_palindrome(&head) == 0)
		printf("Test 4 PASS: [2,3] is not a palindrome\n");
	else
		printf("Test 4 FAIL: [2,3] should not be a palindrome\n");
	free_listint(head);

	/* Test 5: Odd length palindrome */
	head = NULL;
	add_nodeint_end(&head, 1);
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 3);
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 1);
	if (is_palindrome(&head) == 1)
		printf("Test 5 PASS: [1,2,3,2,1] is a palindrome\n");
	else
		printf("Test 5 FAIL: [1,2,3,2,1] should be a palindrome\n");
	free_listint(head);

	/* Test 6: Even length palindrome */
	head = NULL;
	add_nodeint_end(&head, 1);
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 1);
	if (is_palindrome(&head) == 1)
		printf("Test 6 PASS: [1,2,2,1] is a palindrome\n");
	else
		printf("Test 6 FAIL: [1,2,2,1] should be a palindrome\n");
	free_listint(head);

	return (0);
}