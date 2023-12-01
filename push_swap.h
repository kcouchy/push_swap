/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:45:14 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/01 17:06:40 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

# include <stdlib.h>	/*malloc/free/calloc && exit etc*/
# include <unistd.h>	/*write*/
# include <stdio.h>		/*printf*/

/******************************************************************************/
/* Structures                                                                 */
/******************************************************************************/

typedef struct s_list
{
	int				num;
//	int				depth;
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
long	ft_atoi(char *argv);

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
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content 
 * of each node. Creates a new list resulting of the successive applications 
 * of the function ’f’. The ’del’ function is used to delete the content of a 
 * node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @return t_list* Pointer to the head of the new list.
 */
t_list	*ft_lstmap(t_list *lst, int(*f)(int));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content 
 * of each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, int(*f)(int));

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
/* Main Functions                                                             */
/******************************************************************************/

/**
 * @brief Main function
 * 
 * @param argc input
 * @param argv input
 */
void	push_swap(int argc, char **argv);

/******************************************************************************/
/* Sorting Operations                                                         */
/******************************************************************************/

/**
 * @brief does the work of sa (swap a) and sb (swap b): 
 * Swap the first 2 elements at the top of stack a or b.
 * Does nothing if there is only one or no elements in the stack (ft_lstsize).
 * @param list pointer to the head of the stack to swap
 * @param a_b stack name for output (sa\n or sb\n)
 * @return t_list* pointer to the head of the stack, swapped
 */
t_list	*ft_swap2(t_list *list, char a_b);

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of 
// a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of 
// b.
// Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// rrr : rra and rrb at the same time.

#endif
