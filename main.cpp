#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
unsigned long long generateRandLong()
{
    unsigned long long result = 0;
    int iters = rand() % 5+10;
    for (int i = 0; i < iters; i++) {
        result += (rand() % 10) * pow(10, i);
    }
    return result;
}
class Data
{
    public:
    int age;
    int voice;
    int hair;
    Data()
    {
         age =rand()%1000+1;
        voice =rand()%1000+1;
        hair =rand()%1000+1;
    }
    bool operator<(const Data &tempData)const
    {
       if(age != tempData.age)
       {
        return age < tempData.age;
       }
       if(voice != tempData.voice)
       {
        return voice < tempData.voice;
       }
       return hair < tempData.hair;
    }
     bool operator==(const Data &tempData)const
    {
        if(age==tempData.age && voice == tempData.voice && hair==tempData.hair)
        {
            return true;
        }
        return false;
    }
}; 
class Node
{
    public:
    Node* left = nullptr;
    Node* right = nullptr;
    Data data;
};
class BinarySearchTree
{
    public:
    Node* root = nullptr;
    
    bool isTreeEmpty()
    {
        if(root == nullptr)
        {
            return true;
        }
        return false;
    }

    int realsize(Node* newNode)
    {
        if(newNode == nullptr)
        {
            return 0;
        }
        else
        {
            return(realsize(newNode->left)+1+realsize(newNode->right));
        }    
    }
    int size()
    {
        Node* newNode = root;
        int size = realsize(root);
        return size;
    }
    Node* finded(Data data, Node* newNode)
    {
        if (newNode == nullptr)
        {
            return newNode;
        }
        else
        {
            Node* tempnode = root;
            while(tempnode != nullptr)
            {
                if (data == tempnode->data)
                {
                    return tempnode;
                }
                else if(data < tempnode->data)
                {
                    tempnode = tempnode->left;
                }
                else
                {
                    tempnode = tempnode->right;
                }
            }
            return nullptr;
        }
    }
    bool find(Data data)
    {
        Node* tempNode = root;
        if(finded(data,tempNode) != nullptr)
        {
            return true;
        }
        return false;
    }
    void inserted (Data data, Node* aNode)
    {
        if (aNode == NULL)
        {
            //cout << "ayf";
            aNode = new Node;
            aNode->data = data;
            root = aNode;
            return;
        }
        else
        {
            Node* currentNode = root;
            while(currentNode != nullptr)
            {
                if(data < currentNode->data)
                {
                    if(currentNode->left == nullptr)
                    {
                        Node* tempNode = new Node();
                        tempNode->data = data;
                        currentNode->left = tempNode;
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else
                {
                    if(currentNode->right == nullptr)
                    {
                        Node* tempNode = new Node();
                        tempNode->data = data;
                        currentNode->right = tempNode;
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }
    void insert(Data aData)
    {
        if(find(aData) == true)
        {
            return;
        }
        else
        {
            Node* aNode = root;
            inserted(aData, aNode);
        }
        
    }
    Node* minValue(Node* node)
    {
        Node* currentNode = node;
        if(currentNode->left == nullptr)
        {
            return currentNode;
        }
        return minValue(currentNode->left);

    }
    Node* maxValue (Node* node)
    {
        Node* currentNode = node;
        if (currentNode->right == nullptr)
        {
            return currentNode;
        }
        return maxValue(currentNode->right);
    }

    Node* deleteData(Node* helpnode, Data dataToErase)
    {
        if(helpnode == nullptr)
        {
            return nullptr;
        }
            if (dataToErase < helpnode->data)
            {
                helpnode->left = deleteData(helpnode->left,dataToErase);
            }
            else if(helpnode->data < dataToErase)
            {
                helpnode->right = deleteData(helpnode->right,dataToErase);
            }
            else
            {
                if(helpnode->left == nullptr && helpnode->right == nullptr)
                {
                    delete helpnode;
                    return nullptr;
                }
                else if (helpnode->left == nullptr)
                {
                    Node* tempNode = helpnode->right;
                    delete helpnode;
                    return tempNode;
                }
                 else if (helpnode->right == nullptr)
                 {
                    Node* tempNode = helpnode->left;
                    delete helpnode;
                    return tempNode;
                 }
                 else
                 {
                    Node* tempNode = minValue(helpnode->right);
                    helpnode->data= tempNode->data;
                    helpnode->right = deleteData(helpnode->right,tempNode->data);
                 }
            }
            return helpnode;
    }

    void erase(Data data)
    {
            Node* node = root;
            deleteData(node,data);           
    }
    int height2(Node* newNode)
    {
        if( newNode == nullptr)
        {
            return 0;
        }
        else
        {
            int leftheight = height2(newNode->left);
            int rightheight = height2(newNode->right);
            if (leftheight > rightheight)
              return (leftheight + 1);
            else return (rightheight + 1);
        }
         
    }
    int height()
    {
        Node* heaightNode = root;
        int height = height2(heaightNode);
        return height;
    }   
};
bool testBinarySearchTree()
{
    srand(time(NULL));
    const int iters = 80000;
    const int keysAmount = iters * 2;
    const int itersToRangeQueries = 1000;
    vector<Data> data(keysAmount);
    vector<Data> dataToInsert(iters);
    vector<Data> dataToErase(iters);
    vector<Data> dataToFind(iters);
    vector<pair<Data, Data>> dataToRangeQueries;

    for (int i = 0; i < iters; i++)
    {
    dataToInsert[i] = data[generateRandLong() % keysAmount];
    dataToErase[i] = data[generateRandLong() % keysAmount];
    dataToFind[i] = data[generateRandLong() % keysAmount];
    }
    for (int i = 0; i < itersToRangeQueries; i++)
    {
    Data minData = Data();
    Data maxData = Data();
    if (maxData < minData)
    {
    swap(minData, maxData);
    }
    dataToRangeQueries.push_back({minData, maxData});
    }
    BinarySearchTree myTree;
    clock_t myStart = clock();
    for (int i = 0; i < iters; i++)
    {
    myTree.insert(dataToInsert[i]);
    }
    int myInsertSize = myTree.size();
    int myTreeHeight = myTree.height();
    int optimalTreeHeight = log2(myInsertSize) + 1;
    for (int i = 0; i < iters; i++)
    {
    myTree.erase(dataToErase[i]);
    }
    int myEraseSize = myInsertSize - myTree.size();
    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
    if (myTree.find(dataToFind[i]))
    {
    myFoundAmount++;
    }
    }
    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;
    set<Data> stlTree;
    clock_t stlStart = clock();
    for (int i = 0; i < iters; i++)
    {
    stlTree.insert(dataToInsert[i]);
    }
    int stlInsertSize = stlTree.size();
    for (int i = 0; i < iters; i++)
    {
    stlTree.erase(dataToErase[i]);
    }
    int stlEraseSize = stlInsertSize - stlTree.size();
    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
    if (stlTree.find(dataToFind[i]) != stlTree.end())
    {
    stlFoundAmount++;
    }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

    clock_t myRangeStart = clock();
    int myRangeFoundAmount = 0;
    /*for (int i = 0; i < itersToRangeQueries; i++)
    {
    myRangeFoundAmount += myTree.findInRange(dataToRangeQueries[i].first,
    dataToRangeQueries[i].second);
    */
    clock_t myRangeEnd = clock();
    float myRangeTime = (float(myRangeEnd - myRangeStart)) / CLOCKS_PER_SEC;
    clock_t stlRangeStart = clock();
    int stlRangeFoundAmount = 0;
    for (int i = 0; i < itersToRangeQueries; i++)
    {
    const auto& low = stlTree.lower_bound(dataToRangeQueries[i].first);
    const auto& up = stlTree.upper_bound(dataToRangeQueries[i].second);
    stlRangeFoundAmount += distance(low, up);
    }
    clock_t stlRangeEnd = clock();
    float stlRangeTime = (float(stlRangeEnd - stlRangeStart)) / CLOCKS_PER_SEC;
    cout << "My BinaryTree: height = " << myTreeHeight << ", optimal height = " <<
    optimalTreeHeight << endl;
    cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize << ",found amount: " << myFoundAmount << endl;
    cout << "Range time: " << myRangeTime << ", range found amount: "<< endl << endl;
    cout << "STL Tree:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize <<
    ", found amount: " << stlFoundAmount << endl;
    cout << "Range time: " << stlRangeTime << ", range found amount: " <<
    stlRangeFoundAmount << endl << endl;
    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount)
    {
    cout << "The lab is completed" << endl;
    return true;
    }
    cerr << ":(" << endl;
    return false;
}
int main()
{
    srand(time(NULL));
    testBinarySearchTree();
}
