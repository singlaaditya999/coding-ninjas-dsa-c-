#include<iostream>
using namespace std;

/*************
 Driver program to test below functions

****************/

class Polynomial {
    
    public:
    
    int *degCoeff;      // Name of your array (Don't change this)
    int size;
    // Complete the class
        
    
    
    Polynomial()
    {
        degCoeff=new int[5];
        for(int i=0;i<5;i++)
            degCoeff[i]=0;
        size=5;
    }

    Polynomial(Polynomial const &p)
    {
        size=p.size;
        degCoeff=new int [size];
        for(int i=0;i<size;i++)
        {
            degCoeff[i]=p.degCoeff[i];
        }
    }

    void setCoefficient(int degree, int coeff)
		{
			if(degree>=size)
			{
				int newSize=2*size;
				while(newSize<=degree)
				{
					newSize*=2;
				}
				int *newDegCoeff = new int [newSize];
				for(int i=0; i<newSize;i++)
				{
					newDegCoeff[i]=0;
				}
				for(int i=0;i<size;i++)
				{
					newDegCoeff[i]=degCoeff[i];
				}
				size=newSize;
				delete [] degCoeff;
				degCoeff=newDegCoeff;
			}
			degCoeff[degree]=coeff;
		}
    
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial ans;
        int newSize=max(size,p.size);
        int * newArr=new int[newSize];
        for(int i=0;i<newSize;i++)
            newArr[i]=0;
        for(int i=0;i<size;i++)
            newArr[i]+=degCoeff[i];
        for(int i=0;i<p.size;i++)
            newArr[i]+=p.degCoeff[i];
        for(int i=0;i<newSize;i++)
            ans.setCoefficient(i,newArr[i]);
        delete[] newArr;
        
    }

    Polynomial operator-(Polynomial const &p)
    {
        Polynomial ans;
        int newSize=max(size,p.size);
        int * newArr=new int[newSize];
        for(int i=0;i<newSize;i++)
            newArr[i]=0;
        for(int i=0;i<size;i++)
            newArr[i]+=degCoeff[i];
        for(int i=0;i<p.size;i++)
            newArr[i]-=p.degCoeff[i];
        for(int i=0;i<newSize;i++)
            ans.setCoefficient(i,newArr[i]);
        delete[] newArr;
        
    }

    Polynomial operator*(Polynomial const &p)
    {
        Polynomial ans;
        ans.size=size+p.size-2;
        for(int i=0;i<ans.size;i++)
            ans.degCoeff[i]=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<p.size;j++)
            {
                int degree=i+j;
                int coefficient=degCoeff[i]*p.degCoeff[j];
                ans.setCoefficient(degree,coefficient);
            }
        }
        return ans;
    }

    void operator=(Polynomial const &p)
    {
        delete []degCoeff;
        size=p.size;
        degCoeff=new int [size];
        for(int i=0;i<size;i++)
            degCoeff[i]=p.degCoeff[i];
    }


    void print()
    {
        for(int i=0;i<size;i++)
            cout<<degCoeff<<"x"<<i<<" ";
    }
};

 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
