#include "std_lib_facilities.h"
void read_from_file(vector<double>& vd, string file)
{
    ifstream ifs(file);

    for(double d; ifs >> d;)
        vd.push_back(d);
}

class Less_than
{
    double v;
public:
    Less_than(double d) : v{d} {}

    bool operator()(double val){return val < v;}
};

template<typename T>
void v_print(const vector<T>& vec)
{
    for(double val : vec)
        cout << val << endl;
    cout << '\n';
}

int main()
{
//1
    vector<double> vd;
    read_from_file(vd, "source2.txt");
//2
    cout << "VD elements: " << endl;
    v_print(vd);
//3
    vector<int> vi(vd.size());
    copy(vd.begin(), vd.end(), vi.begin());
//4
    cout << "VD+VI elements: " << endl;
    for (int i = 0; i < vd.size(); ++i)
    {
        cout << vd[i] << '\t' << vi[i] << endl;
    }
//5
    double vd_sum = 0;
    for(double d : vd)
    {
        vd_sum += d;
    }
    cout << "\nSum of vd: " << vd_sum << endl;
//6
    double vi_sum = 0;
    for(double d : vi)
    {
        vi_sum += d;
    }
    cout << "\nDifference of vd and vi: " << abs(vi_sum-vd_sum) << endl;
//7
    reverse(vd.begin(), vd.end());
    cout << "VD elements: " << endl;
    v_print(vd);
//8
    double vd_mean = vd_sum / vd.size();
    cout << "The mean of vd: " << vd_mean << endl;
//9
    vector<double> vd2(vd.size());
    copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
    cout << "VD2 elements: " << endl;
    v_print(vd2);
//10
    sort(vd.begin(), vd.end());
    cout << "VD elements: " << endl;
    v_print(vd);
    return 0;
}