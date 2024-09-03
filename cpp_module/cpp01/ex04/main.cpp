/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:31:04 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/24 02:17:50 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ifstream input_file;
    std::ofstream output_file;
    std::string outfile;
    std::string s1;
    std::string s2;
    std::string line;

    if (argc != 4)
    {
        std::cout << "인자를 3개 입력해주세요." << std::endl;
        return (1);
    }
    if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cout << "인자에 값을 입력해주세요" << std::endl;
        return (1);
    }
    input_file.open(argv[1]);
    if (!input_file.is_open())
    {
        std::cout << "입력 파일을 열 수 없습니다." << std::endl;
        return (1);
    }
    outfile = argv[1];
    outfile.append(".replace");
    output_file.open(outfile);
    if (!output_file.is_open())
    {
        std::cout << "출력 파일을 열 수 없습니다." << std::endl;
        return (1);
    }
    
    s1 = argv[2];
    s2 = argv[3];
    while (true)
    {
        size_t pos = 0;

        std::getline(input_file, line);
        while (true)
        {
            pos = line.find(s1, pos);
			if (pos == std::string::npos)
				break ;
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
        }
        output_file << line;
        if (input_file.eof())
            break ;
        output_file << std::endl;
    }
}