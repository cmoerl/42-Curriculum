/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:36:35 by csturm            #+#    #+#             */
/*   Updated: 2024/10/07 11:51:42 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    /* A pointer is a variable that holds the memory address of another variable.
    A pointer needs to be dereferenced with the * operator to access the memory
    location it points to.
    
    A pointer can be re-assigned. This property is useful for the implementation
    of data structures like a linked list, a tree, etc. 
    
    A pointer has its own memory address and size on the stack.*/
    std::string *stringPTR = &str;
    
    /* A reference variable is an alias, that is, another name for an already
    existing variable. A reference, like a pointer, is also implemented by storing
    the address of an object. 
    A reference can be thought of as a constant pointer (not to be confused with a
    pointer to a constant value!) with automatic indirection, i.e., the compiler
    will apply the * operator for you.
    
    A reference cannot be re-assigned, and must be assigned at initialization.
    
    A reference shares the same memory address with the original variable and
    takes up no space on the stack.
    
    Cannot be assigned NULL.
    
    Cannot reference another reference (pointer to a pointer). */
    std::string &stringREF = str;

    std::cout << &str << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";
    
    std::cout << str << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";
    return (0);
}
