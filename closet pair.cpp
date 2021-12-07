#include <bits/stdc++.h>   // Include Everything    

#define x first            // Change word 'first' to word 'x'
#define y second           // Change word 'second' to word 'y'
#define INF 9e18           // Set INF be large number as infinity number

using namespace std;

using point = pair<double, double>; // Set point is pair of double
                                    // first of element is x
                                    // second of element is y

float dst(point p1, point p2)
{ 
  // find the euclidean distance in 2D space
  double dx = p1.x - p2.x;    // diff x
  double dy = p1.y - p2.y;    // diff y
  return sqrt(dx*dx + dy*dy); // formular of euclidean
}

bool cmp_yaxis(point p1, point p2)
{
  // compare function for sorting point by y-axis
  return p1.y > p2.y;
}

/* Definition function of Problem
   + ClosestPair(p:Array[point], L:int, R:int): double 
   + return type is distance of closest point           */
double ClosestPair(vector<point> p, int L, int R);

int main()
{
  /*  Input sector */
  
  // Input `N` as a Number of Points in 2D space
  int n;
  printf("Please Enter N: "); scanf("%d", &n);

  // Create a List of `N` points
  vector<point> p(n);

  for (int i = 0; i < n; ++i) {
    printf(" At point[%d] has (x, y): ", i);
    
    // Input information of a point `i` : x y
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }

  /*  Finding closest distance sector of any 2 points */

  // Sort point `p` by x-axis (defualt of sorting with std::pair<> )
  sort(p.begin(), p.end());

  // Finding `answer` of closest point in list `p` 
  // ClosestPair(p:Array[Point], Left_index = 0, right_index = last)
  double answer = ClosestPair(p, 0, int(p.size())-1);

  /* Output of Problem */
  cout << answer;

  return 0;
}

// Declaration of function ClosestPair()
double ClosestPair(vector<point> p, int L, int R)
{
  
  // Base Case #1: No point to build any distance
  if (R - L + 1 <= 1) return INF;

  // Base Case #2: There is one pair to find distance
  if (R - L + 1 == 2) return dst(p[L], p[R]); 

  /* Recurrence Case (Idea concept): 
       + Divide points into 2 side(Left side and Right side)
       + Combine them with strip area and box scanning
  */

  /*  Divide Section  */
  
  int mid = (L + R) / 2;                // find the `mid` of Index  `L` and `R` 
  point midPoint = p[mid];              // remember the `midPoint`

  double dL = ClosestPair(p, L, mid);   // recursivly left side of points
  double dR = ClosestPair(p, mid+1, R); // recursivly right side of points

  double d = min(dL, dR);               // Let `d` is shortest of closest distance

  /*  Combine Section  */

  // Let `strip` be a list of point that has possible better answer
  vector<point> strip;                  
  for (int i = L; i <= R; ++i) {        // scan each point from Left to Right index
    auto e = p[i];                      // Let `e` be a point in index `i`
    if (abs(e.x - midPoint.x) < d) {    // if point `e` stay in strip area
      strip.push_back(e);               // then append `e` to strip list
    }
  }

  // sort each point in list strip by y-axis (using compare function by y-axis)
  sort(strip.begin(), strip.end(), cmp_yaxis);

  // start box scanning
  for (int cur = 0; cur < (int) strip.size(); ++cur) {
    // let `cur` be the index of point `i`
    // let `nxt` be the next index of each point `i`
    for (int nxt = cur + 1; nxt < (int) strip.size() ; ++nxt) {

      // this point will guarantee that loop will iterate <= 8 times
      if (abs(strip[nxt].y - strip[cur].y) >= d) 
        break; 

      // finding the minimum value
      d = min (d, dst(strip[cur], strip[nxt]));
    }
  
  }

  // return value of closest distance of points in index `L` to `R`
  return d;
}
