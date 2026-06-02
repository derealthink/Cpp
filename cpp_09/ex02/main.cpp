#include "PmergeMe.hpp"


static int validateSing(std::string s)
{
    int i = 0;
    
    if (s[0] == '-'){
        std::cout << "No negative numbers allowed" << std::endl;
        return (0);
    }
    else if (s[0] == '+')
        i++;
    while (i < s.size() - 1){
        if (!isdigit(s[i])){
            std::cout << "Non numerical arguments are not allowed" << std::endl;
            return (0);
        }
        i++;
    }
    long n = strtol(s.c_str(), NULL, 10);
    if (n > INT_MAX){
        std::cout << "Number provided exceeds integer" << std::endl;
        return (0);
    }
    return (1);
}


static int validateAll(int argc, char **argv)
{
    if (argc == 1){
        std::cout << "Not enough arguments provided" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        if (!validateSing(argv[i]))
            return (0);
    }
    return (1);
}

static std::vector<int> argv_to_vector(int argc, char** argv)
{
    std::vector<int> res;
    res.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

static std::deque<int> argv_to_deque(int argc, char** argv)
{
    std::deque<int> res;
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

template <typename T>
static bool is_sorted(const T& container)
{
    if (container.size() < 2)
        return true;
    typename T::const_iterator it = container.begin();
    typename T::const_iterator next = it;
    ++next;

    for (; next != container.end(); ++it, ++next)
    {
        if (*it > *next)
            return false;
        
    }
    return true;
}

