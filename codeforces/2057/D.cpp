using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
struct Node{
   ll answer;
   ll amin;
   ll amax;
};
 
class Segtree{
   private:
   vector<Node> a;
   int dir;
   
   public:
   Segtree(int size, int dir_){
      a = vector<Node>(4*size);
      dir = dir_;
   }
   
   void combine(int v){
      ll newa = max(a[2*v+1].answer,a[2*v+2].answer);
      if(dir == 0){
         newa = max(newa,a[2*v+2].amax - a[2*v+1].amin);
      } else {
         newa = max(newa,a[2*v+1].amax - a[2*v+2].amin);
      }
      
      a[v] = {newa,min(a[2*v+1].amin,a[2*v+2].amin),max(a[2*v+1].amax,a[2*v+2].amax)};
      
   }
   
   void build(int v, int l, int r, vector<ll>& array){
      if(l == r){
         a[v] = {0,array[l],array[l]};
      } else {
         int mid = (l+r)/2;
         
         build(2*v+1,l,mid,array);
         build(2*v+2,mid+1,r,array);
         
         combine(v);
      }
   }
   
   void update(int v, int l, int r, int i, int x){
      if(l == r){
         a[v] = {0,x,x};
      } else {
         int mid = (l+r)/2;
         
         if(i <= mid){
            update(2*v+1,l,mid,i,x);
         } else {
            update(2*v+2,mid+1,r,i,x);
         }
         
         combine(v);
      }
   }
   
   int query(){
      return a[0].answer;
   }
         
   
};
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, q; cin >> n >> q;
        vector<ll> a1(n); //case where max is on the left hand side
        vector<ll> a2(n);
        for(int i = 0; i < n; i++){
            ll temp; cin >> temp;
            a1[i] = temp + i;
            a2[i] = i - temp;
        }
        Segtree st(n, 1);
        Segtree st2(n, 0);
        st.build(0, 0, n - 1, a1);
        st2.build(0, 0, n - 1, a2);
        // for(int i = 0; i < n; i++){
        //     cout << a1[i] << " " << a2[i] << "\n";
        // }
        //looking for the max difference on the left to the right
        //cout << st.getMaxDifference(0, n - 1) << " " << st2.getMaxDifference(0, n - 1) << "\n";
        cout << max(st.query(), st2.query()) << "\n";
        for(int i = 0; i < q; i++){
            ll p, x; cin >> p >> x;
            p--;
            ll nv1 = p + x;
            ll nv2 = p - x;
            st.update(0, 0, n - 1, p, nv1); st2.update(0, 0, n - 1, p, nv2);
            cout << max(st.query(), st2.query()) << "\n";
            //look at array form 0 to p - 1,
        }
    }
}