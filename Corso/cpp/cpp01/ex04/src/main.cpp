#include "../includes/Replace.h"

int	err(string str)
{
	cout << str << std::endl;

	return 1;
}

string	ft_replace(string str, int pos, int replace_len, string replacer)
{
	string	new_string;

	new_string.append(str, 0, pos);
	new_string.append(replacer);
	new_string.append(str.begin() + (pos + replace_len),str.end());

	return new_string;
}

string	replaced_string(string line, string s1, string s2)
{
	int		position = 0;
	int		s2_len = 0;

	while((position = line.find(s1, position + s2_len)) < (line.length() + s2.length()))
	{
		s2_len = s2.length();
		line = ft_replace(line, position, s1.length(), s2);
	}

	return line.append("\n");
}

int	main(int argc, char **argv)
{
	std::ifstream in_file;
	std::ofstream out_file;
	string	filename;
	string	line;

	if (argc != 4)
		return err(ARGUMENTS);
	filename = argv[1];

	in_file.open(filename);

	if (in_file.is_open())
	{
		out_file.open(filename.append(".replace"));
		if (out_file.is_open())
		{
			while (getline(in_file, line))
				out_file << replaced_string(line, argv[2], argv[3]);

			out_file.close();
		}
		else
		{
			in_file.close();
			return err(CREATION);
		}
		in_file.close();
	}
	else
		return err(FILE);

	return 0;
}
