#ifndef Data_HPP
# define Data_HPP

struct Data
{
    private:
        int x;
    public:
        Data(int x);
        Data(const Data &other);
        ~Data();

        Data	&operator = (const Data &rhs);
        void    printState(void);
};

#endif