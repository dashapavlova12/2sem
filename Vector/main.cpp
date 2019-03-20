#include "vector.cpp"
#include <fstream>

int fake_main()
{
    int size = 10;

    std :: ofstream out;
    out.open("vector_print.txt");

    vector<int> a(size);
    out << a << "\n";

    for (int i = 0; i < size; i++)
    {
        a[i] = i*i;
    }

    out << a << "\n";
    vector<int> b = a * 2;

    out << b << "\n";
    vector<int> c = b;

    out << c * 2 << "\n";
    out.close();

    return 0;
}


int main()
{
    fake_main();

    fclose (log_file_memory);
    fclose (log_file_vector);

    return 0;
}
