/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:06:40 by csturm            #+#    #+#             */
/*   Updated: 2024/10/08 11:26:36 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string    replaceLine(std::string line, size_t pos, size_t len, std::string s2)
{
    return (line.substr(0, pos) + s2 + line.substr(pos + len));
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "This program takes three parameters: a file name and two strings\n";
        return (1);
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file\n";
        return (1);
    }
    std::string line;
    std::string filename = argv[1];
    filename += ".replace";
    std::ofstream output(filename.c_str());
    if (!output.is_open())
    {
        std::cout << "Error: could not open output file\n";
        return (1);
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    while (std::getline(file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = replaceLine(line, pos, s1.length(), s2);
            pos += s2.length();
        }
        output << line << std::endl;
    }
    file.close();
    output.close();
    return (0);
}

/* 
    - std::ifstream --> used to read from files
    - std::ofstream --> used to write to files
    - std::fstream --> used to read and write to files
*/