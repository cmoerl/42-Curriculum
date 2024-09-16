/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:25:55 by csturm            #+#    #+#             */
/*   Updated: 2024/09/16 11:44:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using std::cout;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    for (int i = 1; argv[i] != NULL; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
            cout << static_cast<char>(toupper(argv[i][j]));
        if (argv[i + 1] != NULL)
            cout << " ";
    }
    cout << "\n";
    return (0);
}