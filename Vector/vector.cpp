#include "vector.h"

template <typename data_t>
int vector<data_t> :: swap (vector<data_t> & that)
{
    std :: swap (size, that.size);
    std :: swap (data, that.data);

    return 0;
}

template <typename data_t>
vector <data_t> :: vector():
    data(NULL),
    poison(0),
    size(0)
{
    PRINT_LOGS_VTR ("Vector %8d [%8d] was created with zero size", this, 0);
}

template <typename data_t>
vector <data_t> :: vector (const vector<data_t> &that):
    data(NEW data_t [that.size]),
    poison (0),
    size(that.size)
    {
        for (int i = 0; i < that.size; i++)
        {
            data[i] = that.data[i];
        }
        PRINT_LOGS_VTR ("Vector %8d [%8d] was copied to %8d [%8d]", that, that.data, this, data);
    }

template <typename data_t>
vector <data_t> :: vector (vector <data_t> && that):
    data(NULL),
    poison (0),
    size(0)
    {
        swap (that);
        PRINT_LOGS_VTR ("Vector %8d [%8d] was moved", this, data);
    }

template <typename data_t>
vector<data_t> :: vector (size_t size):
    data(NEW data_t [size] {}),
    poison (0),
    size (size)
    {
        PRINT_LOGS_VTR ("Vector %8d [%8d] was created with %d size", this, data, size);
    }

class point;

template <typename data_t>
vector<data_t> :: ~vector ()
{
    clear (poison);
    DELETE (data);

    size = SIZE_DESTRUCT;

    PRINT_LOGS_VTR ("Vector %8d [%8d] was destroyed", this, data);

    data = NULL;
}

template <typename data_t>
const size_t vector<data_t> :: size_() const
{
    return size;
}

template <typename data_t>
const data_t &vector<data_t> :: at (size_t index) const
{
    if (index >= size)
    {
        PRINT_LOGS_VTR ("ERROR index %d out of range", index);
        return poison;
    }
    return data[index];
}

template <typename data_t>
int vector<data_t> :: clear (data_t content)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = content;
    }

    PRINT_LOGS_VTR ("Vector %8d [%8d] was cleared with %d", this, data, content);

    return 0;
}

template <typename data_t>
int vector<data_t> :: resize (size_t count)
{
    if (size < count)
    {
        data_t *new_data = NEW data_t [count]{0};
        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        clear (poison);
        DELETE (data);

        data = new_data;
        size = count;

        PRINT_LOGS_VTR ("Vector %8d [%8d] size was changed to %d", this, data, count);

        return 0;
    }
    if (size > count)
    {
        data_t *new_data = NEW data_t [count]{0};
        for (int i = 0; i < count; i++)
        {
            new_data[i] = data[i];
        }

        clear (poison);
        DELETE (data);

        data = new_data;
        size = count;

        PRINT_LOGS_VTR ("Vector %8d [%8d] size was changed to %d", this, data, count);

        return 0;
    }
}

template <typename data_t>
data_t & vector<data_t> :: operator[] (size_t index)
{
    return data[index];
}

template <typename data_t>
const vector<data_t> & vector<data_t> ::  operator= (const vector & that)
{
    vector copy = that;
    swap(copy);

    PRINT_LOGS_VTR (" # Vector %8d [%8d] was set from %8d [%8d]\n", this, data, that, that.data);

    return *this;
}

template <typename data_t>
const vector<data_t> & vector<data_t> :: operator= (vector && that)
{
    swap(that);

    PRINT_LOGS_VTR (" # Vector %8d [%8d] was moved from %8d [%8d]\n", this, data, that, that.data);

    return *this;
}

template <typename data_t>
std :: istream &operator>> (std :: istream & in, const vector <data_t> & lhs)
{
    for (int i = 0; i < lhs.size_(); i++)
    {
        in >> lhs.data[i];
    }

    return in;
}

template <typename data_t>
std :: ostream &operator<< (std :: ostream & out, const vector <data_t> & lhs)
{
    for (int i = 0; i < lhs.size_(); i++)
    {
        out << lhs.at(i) << " ";
    }

    return out;
}

template <typename data_t>
int operator== (const vector<data_t> & lhs, const vector<data_t> & rhs)
{
    if (lhs.size_() != rhs.size_())
        return 0;
    for (int i = 0; i < lhs.size_(); i++)
    {
        if (lhs.at(i) != rhs.at(i))
            return 0;
    }

    return 1;
}

template <typename data_t>
int operator!= (const vector<data_t> & lhs, const vector<data_t> & rhs)
{
    return !(lhs == rhs);
}

template <typename data_t>
vector<data_t> operator+ (const vector<data_t> & lhs, const vector<data_t> & rhs)
{
    vector<data_t> result (rhs.size_());
    for (int i = 0; i < rhs.size_(); ++i)
    {
        result[i] = lhs.at(i) + rhs.at(i);
    }

    return result;
}

template <typename data_t>
vector<data_t> operator+ (const vector<data_t> & lhs, const data_t & num)
{
    vector<data_t> result (lhs.size_());
    for (int i = 0; i < lhs.size_(); ++i)
    {
        result[i] = lhs.at(i) + num;
    }

    return result;
}

template <typename data_t>
vector<data_t> operator+ (const data_t &num,const vector<data_t> & rhs)
{
    vector<data_t> result (rhs.size_());
    for (int i = 0; i < rhs.size_(); ++i)
    {
        result[i] = rhs.at(i) + num;
    }

    return result;
}

template <typename data_t>
vector<data_t> operator* (const vector<data_t> & lhs, const data_t & num)
{
    vector<data_t> result (lhs.size_());
    for (int i = 0; i < lhs.size_(); ++i)
    {
        result[i] = lhs.at(i) * num;
    }

    return result;
}

template <typename data_t>
vector<data_t> operator* (const data_t &num,const vector<data_t> & rhs)
{
    vector<data_t> result (rhs.size_());
    for (int i = 0; i < rhs.size_(); ++i)
    {
        result[i] = rhs.at(i) * num;
    }

    return result;
}

template <typename data_t>
vector<data_t> operator- (const vector<data_t> & lhs, const vector<data_t> & rhs)
{
    vector<data_t> result (rhs.size_());
    for (int i = 0; i < rhs.size_(); ++i)
    {
        result[i] = lhs.at(i) - rhs.at(i);
    }

    return result;
}

template <typename data_t>
vector<data_t> operator- (const vector<data_t> & lhs, const data_t & num)
{
    vector<data_t> result (lhs.size_());
    for (int i = 0; i < lhs.size_(); ++i)
    {
        result[i] = lhs.at(i) - num;
    }

    return result;
}

template <typename data_t>
vector<data_t> operator- (const data_t &num,const vector<data_t> & rhs)
{
    vector<data_t> result (rhs.size_());
    for (int i = 0; i < rhs.size_(); ++i)
    {
        result[i] = rhs.at(i) - num;
    }

    return result;
}

template <typename data_t>
vector<data_t> operator/ (const vector<data_t>& lhs, const data_t& num)
{
    vector<data_t> result (lhs.size_());

    for (int i = 0; i < lhs.size_(); ++i)
    {
        result[i] = lhs.at(i) / num;}

    return result;
}

void * operator new (size_t size, const char * file, const char * fun, int line)
{
    void * point = calloc(1, size);

    if (point == NULL)
    {
        PRINT_LOGS_MEM ("ERROR memory was not allocated %s %s %d", file, fun, line);
        return point;
    }

    PRINT_LOGS_MEM ("%8d allocated %s %s %d", point, file, fun, line);
    return point;
}

void * operator new[] (size_t size, const char * file, const char * fun, int line)
{
    void * point = calloc(1, size);

    if (point == NULL)
    {
        PRINT_LOGS_MEM ("ERROR memory was not allocated %s %s %d", file, fun, line);
        return point;
    }

    PRINT_LOGS_MEM ("%8d allocated %s %s %d", point, file, fun, line);
    return point;
}

void operator delete (void * p) noexcept
{
    free (p);
}

void operator delete[] (void * p) noexcept
{
    free (p);
}

#undef PRINT_LOGS_VTR
#undef PRINT_LOGS_MEM
#undef NEW
#undef DELETE
