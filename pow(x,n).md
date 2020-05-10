

>
>
>class Solution {
>
>public:
>
>  double myPow(double x, int n) {
>
>​    
>
>​    return hhh(x,n);
>
>​    
>
>  }
>
>  double hhh(double x,long long n)
>
>  {
>
>​    if(n==0)
>
>​      return 1;
>
>​    else if(n>0)
>
>​    {
>
>​      if(n==1)
>
>​        return x;
>
>​      long long i=2;      
>
>​      double res=x;
>
>​      for(;i<n;i*=2)
>
>​      {
>
>​        res*=res;        
>
>​      }
>
>​      i/=2;
>
>​      while(i<n)
>
>​      {
>
>​        res*=x;
>
>​        i++;
>
>​      }
>
>​      return res;     
>
>​    }
>
>​      
>
>​    else 
>
>​    {
>
>​      double temp=hhh(x,-n);
>
>​      return 1.0/temp;
>
>​    }
>
>  }
>
>  
>
>};

>class Solution {
>public:
>    double myPow(double x, int n) {
>        // 特殊情况处理
>        if(n == 0) return 1;
>        if(x == 0) return 0;
>        double ans = 1;
>        // 因为 n 为负时最小可达-2147483648，直接取反时超过int上限，因此特殊处理
>        if(n < 0)
>        {
>            x = 1 / x;
>            ans = x;
>            n = -(n + 1);
>        }
>        // 快速幂
>        while(n > 0)
>        {
>            if(n % 2 > 0) ans *= x;
>            n /= 2;
>            x = x * x;
>        }
>        return ans;
>    }
>};
>
>作者：iswJXkYVv3
>链接：https://leetcode-cn.com/problems/powx-n/solution/c-4ms-81mb-kuai-su-mi-by-iswjxkyvv3/
>来源：力扣（LeetCode）
>著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。