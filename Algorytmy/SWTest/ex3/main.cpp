#include<iostream>
#include <map>
#include <vector>
#include <utility> 

#include <cstdio>

using namespace std;

const int MAX_N = 20;

int N, K;
int grid[MAX_N + 1][MAX_N + 1];
int Answers[MAX_N + 1];

// for_each(block)
// blockDown()
// updateDrid()

class BlockElement
{
public:
    BlockElement():
    i(0),
    j(0),
    checked(false)
    {
    }

    BlockElement(int i, int j, bool checked):
    i(i),
    j(j),
    checked(checked)
    {
    }
    
    int i;
    int j;
    bool checked;
};

class Block
{
public: 
    vector<BlockElement*> elements;
    int nr;
};

typedef vector<Block*> vBlocks;

// class Block
// {
//     int type;
//     std::vector<int,int> neighbours;
// };

typedef map<int,  vector<BlockElement*>* > mapBlocks;

int find_block(int g[MAX_N + 1][MAX_N + 1], int i, int j, mapBlocks* mapka) ;
int move_down(int idx, mapBlocks *mapka, int N);

int main(int argc, char** argv)
{
        int test_case;
        /*
                freopen function below opens input.txt file in read only mode, and afterward,
                the program will read from input.txt file instead of standard(keyboard) input.
                To test your program, you may save input data in input.txt file,
                and use freopen function to read from the file when using cin function.
                You may remove the comment symbols(//) in the below statement and use it.
                Use #include<cstdio> or #include<stdio.h> to use the function in your program.
                But before submission, you must remove the freopen function or rewrite comment symbols(//).
        */
        freopen("input.txt", "r", stdin);
        
        
        /*
                Your program should handle 10 test cases given.
        */
        for(test_case = 1; test_case <= 10; ++test_case)
        {
                int i, j;
                /*
                        Read each test case from standard input.
                        The size of matirx is stored in 'N' and the total number of blocks is stored in 'K'.
                        After, the shape of the matrix is stored in the array 'grid'.
                        For example, if there is no block in the cell(2, 3), grid[2][3] has a value 0.
                        On the other hand, if there is a block 'K' in the cell (2,3), grid[2][3] has a value 'K'.
                */
                cin >> N >> K;

                for (i = 1; i <= N; i++)
                {
                        for (j = 1; j <= N; j++)
                        {
                                cin >> grid[i][j];
                        }
                }
                /////////////////////////////////////////////////////////////////////////////////////////////
                /*
                        Implement your algorithm here.
                        Assume your answer, a sequnce of N numbers, is stored in an array 'Answers'.
                */
                bool bMoveDown = true;
                
                while(bMoveDown)
                {
                    mapBlocks* mapka = new mapBlocks; // [nr_block][[x1,y1][x2,y2]]
                    //map.clear();
                
                    //////////////////////////// find block /////////////////////////////
                    for(i = N; i>=1; i--)
                    {
                        for(j = N; j>=1; j--)
                        {
                            if(test_case == 1 || test_case == 2)
                            {
                                find_block(grid, i, j, mapka);
                                
                            }
                        }
                    }
                    
                    for(mapBlocks::iterator it = mapka->begin();it!=mapka->end();it++)
                    {
                        pair<int, vector<BlockElement*>* > p = (*it);
                        vector<BlockElement*> *v = p.second;
                        for(vector<BlockElement*>::iterator itv = v->begin();itv!=v->end();itv++)
                        {
                            BlockElement* el =  (*itv);
                            cout<<"block_nr:"<<p.first<<"  (i,j) = ["<<el->i<<" , "<<el->j<<" ]"<<endl;
                        }
                    }

                    /////////////////////////// move_down blocks //////////////////////////
                    cout<<"AAAAAAAAAAAAAAAAAAAAAAA"<<endl;
                    bMoveDown = false;
                    for(i = N; i>=1; i--)
                    {
                        for(j = N; j>=1; j--)
                        {
                            if(grid[i][j]!=0)
                            {
                                int& block_nr = grid[i][j];
                                mapBlocks::iterator it = mapka->find(block_nr);
                                if(it != mapka->end())
                                {
                                    pair<int, vector<BlockElement*>* > p = (*it);
                                    vector<BlockElement*> *v = p.second;
        
                                    bool moveDown = true;
                                    for(vector<BlockElement*>::iterator itv=v->begin();itv!=v->end();itv++)
                                    {
                                        BlockElement *el =  (*itv);
                                        cout<<"(i,j) = [ "<<el->i<<","<<el->j<<" ]"<<endl;
                                        if(el->checked == true)
                                        {
                                            cout<<"Blok "<<block_nr<<" prezrobiony"<<endl;
                                            break;
                                        }
                                        if(el->i<N)
                                        {
                                            if(grid[(el->i)+1][el->j] != 0)
                                            {
                                                moveDown = false;
                                                cout<<"@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
                                                el->checked = true;
                                                
                                                break;
                                            }
                                            else{
                                                bMoveDown = true;
                                                cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
                                            }
                                        }
                                        else
                                        {
                                            moveDown = false;
                                            break;
                                        }
                                    }
                                    cout<<"@@@@@@@@@@@@))))))))))))))))"<<endl;
                                    if(moveDown == true)
                                    {
                                        for(vector<BlockElement*>::iterator it=v->begin();it!=v->end();it++)
                                        {
                                            BlockElement *el=  (*it);
                           
                                            if(el->i<N && grid[el->i][el->j]!=0)
                                            {
                                                cout<<"Get DOWN "<<el->i<<" "<<el->j<<"--->"<<grid[el->i][el->j]<<endl;
                                                grid[el->i+1][el->j] = block_nr;
                                                grid[el->i][el->j] = 0;
                                                cout<<"grid["<<el->i<<"]["<<el->j<<"] = "<<grid[el->i][el->j]<<endl;
                                                cout<<"grid["<<el->i+1<<"]["<<el->j<<"] = "<<grid[el->i+1][el->j]<<endl;
                                            }
                                        }
                                    }
                                }                     
                            }
                        }
                    }
                
                    mapka->clear();
                    delete mapka;
                    mapka = NULL;
                }        
                for (i = 1; i <= N; i++) 
                {
                    for (j = 1; j <= N; j++) 
                    {
                        cout<<" "<<grid[i][j];
                    }
                    cout<<endl;
                }
                
                for (i = 1; i <= N; i++) 
                {       
                    Answers[i] = grid[N][i];
                }
                
                /////////////////////////////////////////////////////////////////////////////////////////////

                //for (i = 1; i <= N; i++) Answers[i] = -1;

                // Print the answer to standard output(screen). 
                cout << "#" << test_case;
                for (i = 1; i <= N; i++) cout << " " << Answers[i];
                cout << endl;
        }

        return 0;//Your program should return 0 on normal termination.
}

int find_block(int g[MAX_N + 1][MAX_N + 1], int i, int j, mapBlocks *mapka) 
{
    if(g[i][j] != 0)
    {
        int &block_nr = g[i][j];
        cout<<"-- ["<<i<< " , " <<j<<" ] "<<block_nr<<endl;
        
        vector<BlockElement*> *v = NULL;
        mapBlocks::iterator it = mapka->find(block_nr);
        
        if(it == mapka->end())
        {
            v = new vector<BlockElement*>;
        }
        else
        {
            pair<int, vector<BlockElement*>* > p = (*it);
            v = p.second;
            
        }
        BlockElement *el = new BlockElement(i,j,false);
        v->push_back(el);
            
        mapka->insert(make_pair<int, vector<BlockElement*>* >(block_nr,v));
    }
#if 0
        pair<ini,int> itemCoords = make_pair<int,int>(i,j);
        vector<pair<int,int> v;
        v.push_back(itemCoords);
        
        pair<int,vector<pair<ini,int> > > vItemCoords = make_pair(block_nr, v)
        
        mapka->insert()
        vector<pair<int,int> > block_items = new vector<pair<int,int> >;
        pair<int,int> p = make_pair<int,int>(i,j);
        
        block_items->push_back(p);
#endif       
#if 0        
        if(mapka->find(block_nr) == mapka->end())
        {
            vector<pair<int,int> > *block_items = new vector<pair<int,int> >;
            pair<int,int> p = make_pair<int,int>(i,j);
        
            block_items->push_back(p);
    
        
            ////////////////////////////////////////////////////////////////////////
            /// Horizoontally
            ////////////////////////////////////////////////////////////////////////
            // j+1 
            if(g[i][j+1] == block_nr && j<N)
            {
                block_items->push_back(make_pair<int,int>(i,j+1));
                
                if(g[i+1][j+1] == block_nr && j<N && i<N)
                {
                    block_items->push_back(make_pair<int,int>(i+1,j+1));
                    block_items->push_back(make_pair<int,int>(i+1,j));
                }
                else if(g[i-1][j+1] == block_nr && j<N && i>0)
                {
                    block_items->push_back(make_pair<int,int>(i-1,j+1));
                    block_items->push_back(make_pair<int,int>(i-1,j));
                }
            }
            
            // j-1
            if(g[i][j-1] == block_nr && j>0)
            {
                block_items->push_back(make_pair<int,int>(i,j-1));
                
                if(g[i+1][j-1] == block_nr && j>0 && i<N) // j>0 cond no needed
                {
                    block_items->push_back(make_pair<int,int>(i+1,j-1));
                    block_items->push_back(make_pair<int,int>(i+1,j));
                }
                else if(g[i-1][j-1] == block_nr && j>0 && i>0)
                {
                    block_items->push_back(make_pair<int,int>(i-1,j-1));
                    block_items->push_back(make_pair<int,int>(i-1,j));
                }
            }
            ////////////////////////////////////////////////////////////////////////
            /// Vertically
            ////////////////////////////////////////////////////////////////////////
            // i+1 
            if(g[i+1][j] == block_nr && i<N)
            {
                block_items->push_back(make_pair<int,int>(i+1,j));
                
                if(g[i+1][j+1] == block_nr && j<N && i<N)
                {
                    block_items->push_back(make_pair<int,int>(i+1,j+1));
                    block_items->push_back(make_pair<int,int>(i,j+1));
                }
                else if(g[i+1][j-1] == block_nr && j>0 && i<N)
                {
                    block_items->push_back(make_pair<int,int>(i+1,j-1));
                    block_items->push_back(make_pair<int,int>(i,j-1));
                }
            }
            
            // i-1
            if(g[i-1][j] == block_nr && i>0)
            {
                block_items->push_back(make_pair<int,int>(i-1,j));
                
                if(g[i-1][j+1] == block_nr && i>0 && j<N) // j>0 cond no needed
                {
                    block_items->push_back(make_pair<int,int>(i-1,j+1));
                    block_items->push_back(make_pair<int,int>(i,j+1));
                }
                else if(g[i-1][j-1] == block_nr && j>0 && i>0)
                {
                    block_items->push_back(make_pair<int,int>(i-1,j-1));
                    block_items->push_back(make_pair<int,int>(i,j-1));
                }
            }
            mapka->insert(make_pair(block_nr, block_items));
        }
#endif
    
    
    return 0;
}
int move_down(int idx, mapBlocks *mapka, int N)
{
#if 0

    mapBlocks::iterator it = mapka->find(idx);
    if(it == mapka->end())
        return -1;
    
    int res = 0;
    
    pair<int, vector<pair<int,int> >* > p = (*it);
    cout<< p.first<<endl;
    vector<pair<int,int> >* v = p.second;
     
    for(vector<pair<int,int> >::iterator it=v->begin();it!=v->end();it++)
    {
        pair<int,int> p =  (*it);
        cout<<(*it).first<<","<<(*it).second<<endl;
        int i = (*it).first;
        int j = (*it).second;
        if(i<N)
        {
            grid[i,j];
            res++;
        }
    }
    if(v->size()==res)
    {
        cout<<"OK down"<<endl;
        
        for(vector<pair<int,int> >::iterator it=v->begin();it!=v->end();it++)
        {
            pair<int,int> p =  (*it);
            (*it).first = (*it).first+1;
        }    
        
        return 0;
    }
    
    
    return -1;
#endif
    
}

// int check_neighbours(int i, int j, int block_nr)
// {
//     if((g[i][j+1] == block_nr && j<N))
//     {
//     }
//     else
//     {
//     }
//     
//     if((g[i][j+1] == block_nr && j<N))
//     {
//     }
//     if((g[i][j+1] == block_nr && j<N))
//     {
//     }
//     if((g[i][j+1] == block_nr && j<N))
//     {
//     }
// }