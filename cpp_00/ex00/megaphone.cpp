#include <iostream>

char *to_upper(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
        i++;
    }
    return (s);
}

int main(int argc, char **argv){
    if (argc > 2)
        return (1);
    else if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else {
        char *res = to_upper(argv[1]);
        std::cout << res << '\n';
    }
    return (0);
      
}