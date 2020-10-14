#include "connectednessarray.h"
#include "connectednessfullunion.h"
#include "connectednesstree.h"
#include "connectednessweightedunion.h"
#include <iostream>

int main( )
{
    //    ConnectednessArray connect( 20 );
    //    connect.Display( );
    //    connect.Read( );

    //    ConnectednessTree connectTree( 20 );
    //    connectTree.Display( );
    //    connectTree.Read( );

    //    ConnectednessWeightedUnion conWeiUni( 20 );
    //    conWeiUni.Display( );
    //    conWeiUni.Read( );

    ConnectedNessFullUnion full( 10 );
    full.Display( );
    full.Read( );
}
