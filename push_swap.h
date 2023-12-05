/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:45:14 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/05 18:04:24 by kcouchma         ###   ########.fr       */
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
 * @brief takes the inputs and checks for duplicates
 * @param argc input
 * @param argv input
 * @return int returns 0 if all ints are unique, otherwise error() 
 * (Prints "Error\n" to the standard output and returns 1).
 */
int		is_dup(int argc, char **argv);

/**
 * @brief Runs all of the above check functions to make sure the input is valid
 * @param argc input
 * @param argv input
 * @return int returns 0 if all argv are fine, otherwise 1.
 */
int		ft_checkinputs(int argc, char **argv);

/******************************************************************************/
/* errors.c                                                                   */
/******************************************************************************/

/**
 * @brief to add to the return line in case of error. Prints "Error\n" to the 
 * standard output.
 * @return int returns 1.
 */
int		ft_error(void);

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
 * @param new The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Adds the node ’new’ at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes and frees the given node and every successor of that node, 
 * using the function ’del’ and free(3). Finally, the pointer to the list 
 * must be set to NULL.
 * @param lst The address of a pointer to a node.
 */
void	ft_lstclear(t_list **lst);

/**
 * @brief Copies a list node by node.
 * @param lst The address of a pointer to a node.
 * @return t_list* duplicate list
 */
t_list	*ft_lstmap(t_list *lst);

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content 
 * of each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(int *));

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return t_list* Last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return int The length of the list.
 */
int		ft_lstsize(t_list *lst);

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
/* Combined Sorting Operations                                                */
/******************************************************************************/

/**
 * @brief does the work of sa (swap a) and sb (swap b) at the same time: 
 * Swap the first 2 elements at the top of stack a and b.
 * Does nothing if there is only one or no elements in either stack (ft_lstsize)
 * @param a_list pointer to the head of the a_stack to swap
 * @param b_list pointer to the head of the b_stack to swap
 * @return 0 if there was a swap for both, 1 if no swap (<= 1 elements in stack)
 */
int		ft_ss(t_list *a_list, t_list *b_list);

/**
 * @brief does the work of ra (rotate a) and rb (rotate b) at the same time:
 * Shift up all elements of stack a_list and b_list by 1.
 * The first element becomes the last one.
 * Does nothing if either stack is empty or contains only 1 element.
 * @param a_list double pointer to the head of the target a_list
 * @param b_list double pointer to the head of the target b_list
 * @return 0 if there was a rotation for both, 1 if not (<= 1 elements in stack)
 */
int		ft_rr(t_list **a_list, t_list **b_list);

/**
 * @brief does the work of rra (reverse rotate a) and rrb (reverse rotate b) at 
 * the same time:
 * Shift down all elements of stack a_list and b_list by 1.
 * The last element becomes the first one.
 * Does nothing if either stack is empty or contains only 1 element.
 * @param a_list double pointer to the head of the target a_list
 * @param b_list double pointer to the head of the target b_list
 * @return 0 if there was a rotation for both, 1 if not (<= 1 elements in stack)
 */
int		ft_rrr(t_list **a_list, t_list **b_list);

/******************************************************************************/
/* push_swap_utils.c                                                          */
/******************************************************************************/

/**
 * @brief Utility to print a list to the standard output to check progress.
 * @param stack pointer to a list to print.
 */
void	print_list(t_list *stack);

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
 * @brief Find the median value of a stack. If there is an even number of 
 * elements, returns the larger median value.
 * @param a_stack pointer to a list to check.
 * @return int median value of the list.
 */
int		ft_findpivot(t_list *a_stack);

/******************************************************************************/
/* Main Functions                                                             */
/******************************************************************************/

/**
 * @brief Converts inputs into a linked list (t_list), stored under ->num
 * 
 * @param argc input
 * @param argv input
 * @return t_list* created list, NULL if malloc fails.
 */
t_list	*ft_makelist(int argc, char **argv);

/**
 * @brief Sorts list and generates output when the input consists of 2 or 3 
 * elements.
 * @param a_stack input stack once checked
 */
void	ft_simple_sort(t_list *a_stack);

/**
 * @brief Main function
 * 
 * @param argc input
 * @param argv input
 * @return 0 if ok, 1 in case of error
 */
int		push_swap(int argc, char **argv);

#endif
