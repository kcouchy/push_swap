/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:45:14 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/14 18:24:30 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

# include <stdlib.h>		/*malloc/free/calloc && exit etc*/
# include <unistd.h>		/*write*/
# include "libft/libft.h"	/*includes my libft.h*/

/******************************************************************************/
/* Structures                                                                 */
/******************************************************************************/

typedef struct s_list
{
	int				index;
	int				num;
	struct s_list	*next;
}					t_list;

/******************************************************************************/
/* check_inputs.c                                                             */
/******************************************************************************/

/**
 * @brief checks the inputs to see if they contain only numbers, can start with 
 * either '-' or '+'.
 * @param argc input
 * @param argv input
 * @return int returns 0 if all argv are fine, otherwise 
 * error() (Prints "Error\n" to the standard output and returns 1).
 */
int		is_not_num(int argc, char **argv);

/**
 * @brief checks the inputs one at a time to see if they are a valid int.
 * @param argv 
 * @return long returns number is a valid int, otherwise returns -2147483649 
 * (beyond min int so invalid).
 */
long	ftps_atoi(char *argv);

/**
 * @brief Compares two strings character by character, returns the difference.
 * @param s1 pointer to the first input string to compare
 * @param s2 pointer to the other input string to compare
 * @return int the difference, if any, between the two strings
 */
int		ft_strcmp(const char *s1, const char *s2);

/**
 * @brief takes the inputs and checks for duplicates using ft_strcmp
 * @param argc input
 * @param argv input
 * @return int returns 0 if all ints are unique, otherwise error() 
 * (Prints "Error\n" to the standard output and returns 1).
 */
int		is_dup(int argc, char **argv);

/**
 * @brief Runs all of the above check functions to make sure the input is valid.
 * @param argc input
 * @param argv input
 * @return int returns 0 if all argv are fine, otherwise 1.
 */
int		ft_checkinputs(int argc, char **argv);

/******************************************************************************/
/* make&mod_lists.c                                                           */
/******************************************************************************/

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member variable 
 * 'int' is initialized with the value of the parameter 'num'. The 
 * variable ’next’ is initialized to NULL.
 */
t_list	*ft_lstnew(int num);

/**
 * @brief Adds the node ’new’ at the beginning of the list. *lst 
 * @param lst The address of a pointer to the first link of a list.
 * @param new A pointer to the node to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Adds the node ’new’ at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new A pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Duplicates and mallocs a list node by node.
 * @param lst A pointer to the first link of a list.
 * @return t_list* A pointer to the first link of the duplicate list.
 */
t_list	*ft_lstmap(t_list *lst);

/**
 * @brief Converts inputs from the standard input into a linked list (t_list), 
 * with the value stored in the variable ->num.
 * @param argc input
 * @param argv input
 * @return t_list* created list, NULL if malloc fails.
 */
t_list	*ft_makelist(int argc, char **argv);

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return int The length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Deletes and frees the given node and every successor of that node, 
 * using the function ’del’ and free(3). Finally, the pointer to the list 
 * must be set to NULL.
 * @param lst The address of a pointer to a node.
 */
void	ft_lstclear(t_list **lst);

/**
 * @brief Fills in the index value for the linked list. Calls ft_sort_stack
 * to make a sorted duplicate list, then applies the index value to the unsorted
 * a_stack list.
 * @param a_stack Address of a pointer to the beginning of the list.
 * @return int returns ft_error() if error, 0 if all goes well.
 */
int		ft_addindex(t_list **a_stack);

/******************************************************************************/
/* Sorting Operations                                                         */
/******************************************************************************/

/**
 * @brief does the work of sa (swap a) or sb (swap b): 
 * Swap the first 2 elements at the top of stack a or b.
 * Does nothing if there is only one or no elements in the stack (ft_lstsize).
 * @param list pointer to the head of the stack to swap
 * @param a_b stack name for output (sa\n or sb\n)
 * @return 0 is there was a swap, 1 if no swap (<= 1 elements in stack)
 */
int		ft_sa_sb(t_list *list, char a_b);

/**
 * @brief does the work of pa (push a) or pb (push b):
 * Take the first element at the top of source_list and put it at the top of 
 * target_list.
 * Does nothing if source_list is empty.
 * @param source_list double pointer to the head of the source list
 * @param target_list double pointer to the head of the target list
 * @param a_b the push target list for output (pa\n or pb\n)
 * @return 0 is there was a swap, 1 if no swap (source_list has no elements) 
 */
int		ft_pa_pb(t_list **source_list, t_list **target_list, char a_b);

/**
 * @brief does the work of ra (rotate a) or rb (rotate b):
 * Shift up all elements of stack list by 1.
 * The first element becomes the last one.
 * Does nothing if stack is empty or contains only 1 element.
 * @param list double pointer to the head of the target list
 * @param a_b stack name for output (ra\n or rb\n)
 * @return int 
 */
int		ft_ra_rb(t_list **list, char a_b);

/**
 * @brief does the work of rra (reverse rotate a) or rrb (reverse rotate b):
 * Shift down all elements of stack list by 1.
 * The last element becomes the first one.
 * Does nothing if stack is empty or contains only 1 element.
 * @param list double pointer to the head of the target list
 * @param a_b stack name for output (ra\n or rb\n)
 * @return int 
 */
int		ft_rra_rrb(t_list **list, char a_b);

/******************************************************************************/
/* push_swap_utils.c                                                          */
/******************************************************************************/

// /**
//  * @brief Utility to print a list to the standard output to check progress.
//  * @param stack pointer to a list to print.
//  * @param name name to print before the contents.
//  */
// void	print_list(t_list *stack, char *name);

/**
 * @brief to add to the return line in case of error. Prints "Error\n" to the 
 * standard output.
 * @return int returns 1.
 */
int		ft_error(void);

/**
 * @brief Swaps the value ->num of two t_list pointers.
 * @param stack1 first pointer to swap.
 * @param stack2 second pointer to swap.
 */
void	swap_nums(t_list *stack1, t_list *stack2);

/**
 * @brief Checks the list pairwise to see if it is in ascending order.
 * @param stack pointer to a list to check.
 * @return int 0 if correctly sorted, 1 if an unsorted pair is found.
 */
int		ft_check_list(t_list *stack);

/**
 * @brief Takes a list, duplicates it using ft_lstmap, then sorts the duplicate.
 * @param stack pointer to a list to copy and sort.
 * @return t_list* duplicate of the input stack.
 */
t_list	*ft_sort_stack(t_list *stack);

/**
 * @brief Find the median num value of a stack using the index value.
 * If there is an even number of elements, returns the larger median value.
 * @param a_stack pointer to a list to check.
 * @return int median value of the list.
 */
int		ft_findpivot(t_list *a_stack);

/******************************************************************************/
/* quick_sort_utils.c                                                         */
/******************************************************************************/

/**
 * @brief Utility to rotate the given stack to bring the value stocked at 
 * 'depth' to the top.
 * @param stack input stack to search within and rotate.
 * @param a_b identity of the stack for naming conventions ('a' or 'b').
 * @param depth the current depth of the value within the stack.
 * @param size the total size of the stack to rotate
 * variable offset to ensure the utility works in both cases. 
 */
void	ft_turny(t_list **stack, char a_b, int depth, int size);

/**
 * @brief B2A Rotating A
 * In order to the b2a function to work, the largest value must be present in 
 * the a_stack. This function finds the biggest index (number) in b_stack, and 
 * pushes it to a_stack.
 * @param a_stack Target stack for the push.
 * @param b_stack Stack containing all partially sorted values 
 * (after quicksort a2b)
 */
void	ft_big2a(t_list **a_stack, t_list **b_stack);

/**
 * @brief B2A Rotating A
 * Once the largest index (number) is in the a_stack, this function takes the 
 * value on top of the b_stack, and finds the best position in a_stack to place 
 * it. To do this, it finds the next biggest number in a_stack, and returns its
 * position.
 * @param a_stack the stack to search for the correct spot to transfer.
 * @param index index in b_stack to find the closest (next largest) value to.
 * @return int Returns the position in a_stack of the closest (next largest) 
 * value to that at the top of b_stack.
 */
int	ft_closest(t_list *a_stack, int index);

/******************************************************************************/
/* Main Functions - push-swap.c                                               */
/******************************************************************************/

/**
 * @brief Sorts list and generates output when the input consists of 2 or 3 
 * elements.
 * @param a_stack input stack once checked
 */
// void	ft_simple_sort(t_list **a_stack);
void	ft_simple_sort(t_list **a_stack, t_list **b_stack, int argc);

/**
 * @brief 
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	quicksort_a2b(t_list **a_stack, t_list **b_stack);

/**
 * @brief Takes the partially sorted list in b_stack, and sorts it back into 
 * a_stack.
 * @param a_stack Target (empty) stack for sorted list.
 * @param b_stack Stack containing partially sorted results of quicksort_a2b.
 */
void	quicksort_b2a(t_list **a_stack, t_list **b_stack);

/**
 * @brief Main function - checks there are >1 inputs, that they are valid 
 * integers within int range,
 * Constructs the a_stack, initialises the b_stack. 
 * If the stack is already sorted, returns. 
 * If the stack is 2 or 3 elements, sorts it then returns.
 * Otherwise calls push_swap to sort the stack.
 * @param argc input
 * @param argv input
 * @return 0 if ok, 1 in case of error
 */
int		main(int argc, char **argv);

#endif
