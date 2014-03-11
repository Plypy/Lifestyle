#include <iostream>
#include <fstream>
#include <iomanip>

void encipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long * const k)
{
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0;
    unsigned long delta = 0x9e377989;
    unsigned long n = 32;
    while (n-- > 0)
    {
        y += (z<<4^z>>5)+z^sum+k[sum&3];
        sum += delta;
        z += (y<<4^y>>5)+y^sum+k[sum>>11&3];
    }
    w[0] = y;
    w[1] = z;
}

void decipher(
    const unsigned long * const v,
    unsigned long * const w,
    const unsigned long * const k)
{
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0xc6ef3720;
    unsigned long delta = 0x9e3779b9;
    unsigned long n = 32;
    while (n-- > 0)
    {
        z -= (y<<4^y>>5)+y^sum+k[sum>>11&3];
        sum -= delta;
        y -= (z<<4^z>>5)+z^sum+k[sum&3];
    }
    w[0]=y;w[1]=z;
}

using namespace std;
int main()
{
    const int nchar = 2*sizeof(long);
    const int kchar = 2*nchar;
    
    string op;
    string key;
    string infile;
    string outfile;
    cout << "please enter input file name, output file name, and key:\n";
    cin >> infile >> outfile >> key;
    while (key.size()<kchar)
        key+='0';
    ifstream inf(infile.c_str());
    ofstream outf(outfile.c_str());
    const unsigned long*k = reinterpret_cast<const unsigned long*>(key.data());
    if(!inf||!outf)
    {
        cout << "bad file name";
        exit(1);
    }
    unsigned long inptr[2];
    char outbuf[nchar+1];
    outbuf[nchar]=0;
    unsigned long * outptr = reinterpret_cast<unsigned long*>(outbuf);
    inf.setf(ios_base::hex, ios_base::basefield);
    
    while (inf>>inptr[0]>>inptr[1]){
        decipher(inptr,outptr,k);
        outf<<outbuf;}
    inf.close();
    outf.close();
    return 0;
}
