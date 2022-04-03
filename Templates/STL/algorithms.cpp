#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define all(c) c.begin(), c.end()
#define pb push_back
#define F first
#define S second
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define debug(x) cout<<#x<<" : "<<x<<endl;
#define debug2(x,y) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<" , "<<#z<<" : "<<z<<endl;
#define tr(c , s) for(auto x : c ) {cout<< x << s;} cout<< endl;
signed main()
{

//Heaps
    vector< int > hp{1, 3,8,9,4,5,6,7, 2 };
    make_heap(all(hp));
    //    for(auto x :  v ) cout<< x<< " ";
    hp.push_back(10);
    push_heap(all(hp));
    //    for(auto x :  v ) cout<< x<< " ";
    pop_heap(all(hp));
    hp.pop_back();
    //    for(auto x :  v ) cout<< x<< " ";

    vector<int> v1 = {1, 3, 4, 5, 20, 30};
    vector<int> v4 = {1, 3, 4, 5, 6, 20, 25, 30};
//includes
    /*
    includes(v4.begin(), v4.end(), v1.begin(), v1.end())?
    cout << "v4 includes v1":
    cout << "v4 does'nt include v1";*/

//Sorting

    vector< int > srt{8 , 3 ,4, 2 , 1 , 0 , 7 , 9};
    //    sort(all(srt));
    //    tr(srt , " " );

    //to sort partially from beginning to middle and rest are in unspecified order
    //    partial_sort(srt.begin() , srt.begin() +  4, srt.end());
    //    tr(srt , " ");

    //gives nth element if it is sorted;
    //    nth_element(srt.begin() , srt.begin() + 4 , srt.end());
    //    cout<< *(srt.begin() + 4)<<endl;
    //    tr(srt , " ");

    //inplace_merge to merge two containers and sort them ;

//Partition
    /*partition(all(srt) , [](int a ){
        return a%2 == 0;
    });
    tr(srt , " ");
    auto  pp = partition_point(all(srt) , [](int a ){
        return a%2 == 0;
    });
    cout<<pp - srt.begin() << endl;*/


    vector< int > temp(v1.size());
//    partial_sum(all(v1) , temp.begin() );
//    tr(temp , " " );
    /*if(all_of(all(v1) , [](int a ){return a%2 == 0; })) cout<< "All are even\n";
    else if(any_of(all(v1) , [](int  a){ return a%2==0;})) cout<< "At least one element even\n";
    else if(none_of(all(v1) , [](int a ){return a%2 == 0; })) cout<<"None of even\n";
*/

//    string a  = "abcdefgh" , b = "abcdyz";
//    if(lexicographical_compare(all(a) , all(b))) cout << "a is greater than b \n";
//    else cout<<"a is less than b \n";

//Copy
    vector< int > v3 ;
    //    copy(all(v1) ,back_inserter(v3) );
    //    tr(v3 , " ");

//fill
//    vector< int > v5(10);
//    int a[5];
//    fill(a , a + 5 , 45);
//    tr(a , " ");

//iota
    vector< int > v6(10);
    iota(all(v6) , 45);
//    tr(v6 , " ");

// erase , remove , unique;
    vector< int > v2 = {1 , 1 , 2  , 2  , 2 , 3 , 1 , 1 , 2 , 3 , 4 , 1, 3 ,2 ,3 , 2 , 2, 1};
//    v2.erase(v2.begin()+2 , v2.begin() + 5);
//    tr(v2 , " ");

    sort(all(v2));
    v2.erase(unique(all(v2)) , v2.end());
    tr(v2 , " ");


}
