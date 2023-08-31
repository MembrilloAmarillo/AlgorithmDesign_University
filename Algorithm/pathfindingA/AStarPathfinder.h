#ifndef _A_STAR_PATHFINDER_H_
#define _A_STAR_PATHFINDER_H_

#include <algorithm>

#include "Small_Vector.h"

template <size_t N>
struct AStar {
    Small_Vector<size_t, N> Adyacent;
    Small_Vector<size_t, N> Path;
    Small_Vector<size_t, N> Closed;
    Small_Vector<size_t, N> Opened;
    Small_Vector<float , N> Distance;
    Small_Vector<float , N> Heuristic; // Estimated distance
    Small_Vector<float , N> ComputedDistance;
    
    float (*estimate_distance)(size_t, size_t);
    float (*distance)(size_t, size_t);
    
};

template <size_t N>
bool
not_in( const Small_Vector<size_t, N>& V, size_t value )
{
    for( auto x : V )
    {
        if ( x == value )
        {
            return true;
        }
    }
}

template <size_t N>
void
ComputeAStar( AStar<N>& A, size_t begin, size_t target )
{
    bool found = false;
    size_t current = begin;
    A.Distance[current] = 0;
    A.Heuristic[current] = A->estimate_distance( current, target );
    A.ComputedDistance[current] = A.Distance[current] + A.Heuristic[current];
    
    std::make_heap(A.Opened, A.Opened.begin(), A.Opened.end() );
    A.Opened.push_back(current);
    std::push_heap(A.Opened, A.Opened.begin(), A.Opened.end() );
    
    while( !found && A.Opened.size() > 0 )
    {
        current = A.Opened.peek_back();
        std::pop_heap(A.Opened, A.Opened.begin(), A.Opened.end() );
        A.Opened.pop_back();
        A.Closed.push_back( current );
        if ( current == target )
        {
            found = true;
        }
        else
        {
            for( size_t j : A.Adyacent )
            {
                if ( not_in( A.Closed, j ) )
                {
                    if ( not_in( A.Opened, j ) )
                    {
                        A.Path[j] = current;
                        A.Distance[j] = A.Distance[current] + A->distance(current, j);
                        A.Heuristic[j] = A->estimated_distance(j, target);
                        A.ComputedDistance[j] = A.Distance[j] + A.Heuristic[j];
                    }
                    else
                    {
                        float distance = A->distance(current, j);
                        if( A.Distance[j] > (A.Distance[current] + distance) )
                        {
                            A.Path[j] = current;
                            A.Distance[j] = A.Distance[current] + distance;
                            A.ComputedDistance[j] = A.Distance[j] + A.Heuristic[j];
#if 0
                            std::make_heap( A.Opened, A.Opened.begin(), A.Opened.end() );
#endif
                        }
                    }
                }
            }
        }
    }
}

#endif // _A_STAR_PATHFINDER_H_
