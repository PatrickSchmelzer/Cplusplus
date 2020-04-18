//
//#include <iostream>
//#include <queue>
//using namespace std;
//#define N 3 
//
//// state space tree nodes 
//struct Node
//{
//    // stores the parent node of the current node 
//    // helps in tracing path when the answer is found 
//    Node* parent;
//
//    // stores matrix 
//    int mat[N][N];
//
//    // stores blank tile coordinates 
//    int x, y;
//
//    // stores the number of misplaced tiles 
//    int cost;
//
//    // stores the number of moves so far 
//    int level;
//};
//
//// Function to print N x N matrix 
//void printMatrix(int mat[N][N])
//{
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N; j++)
//            printf("%d ", mat[i][j]);
//        printf("\n");
//    }
//}
//
//// Function to allocate a new node 
//Node* newNode(int mat[N][N], int x, int y, int newX,
//    int newY, int level, Node* parent)
//{
//    Node* node = new Node;
//
//    // set pointer for path to root 
//    node->parent = parent;
//
//    // copy data from parent node to current node 
//    memcpy(node->mat, mat, sizeof node->mat);
//
//    // move tile by 1 position 
//    swap(node->mat[x][y], node->mat[newX][newY]);
//
//    // set number of misplaced tiles 
//    node->cost = INT_MAX;
//
//    // set number of moves so far 
//    node->level = level;
//
//    // update new blank tile cordinates 
//    node->x = newX;
//    node->y = newY;
//
//    return node;
//}
//
//// botton, left, top, right 
//int row[] = { 1, 0, -1, 0 };
//int col[] = { 0, -1, 0, 1 };
//
//// Function to calculate the number of misplaced tiles 
//// ie. number of non-blank tiles not in their goal position 
//int calculateCost(int initial[N][N], int final[N][N])
//{
//    int count = 0;
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            if (initial[i][j] && initial[i][j] != final[i][j])
//                count++;
//    return count;
//}
//
//// Function to check if (x, y) is a valid matrix cordinate 
//int isSafe(int x, int y)
//{
//    return (x >= 0 && x < N && y >= 0 && y < N);
//}
//
//// print path from root node to destination node 
//void printPath(Node* root)
//{
//    if (root == NULL)
//        return;
//    printPath(root->parent);
//    printMatrix(root->mat);
//
//    printf("\n");
//}
//
//// Comparison object to be used to order the heap 
//struct comp
//{
//    bool operator()(const Node* lhs, const Node* rhs) const
//    {
//        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
//    }
//};
//
//// Function to solve N*N - 1 puzzle algorithm using 
//// Branch and Bound. x and y are blank tile coordinates 
//// in initial state 
//void solve(int initial[N][N], int x, int y,
//    int final[N][N])
//{
//    // Create a priority queue to store live nodes of 
//    // search tree; 
//    priority_queue<Node*, std::vector<Node*>, comp> pq;
//
//    // create a root node and calculate its cost 
//    Node* root = newNode(initial, x, y, x, y, 0, NULL);
//    root->cost = calculateCost(initial, final);
//
//    // Add root to list of live nodes; 
//    pq.push(root);
//
//    // Finds a live node with least cost, 
//    // add its childrens to list of live nodes and 
//    // finally deletes it from the list. 
//    while (!pq.empty())
//    {
//        // Find a live node with least estimated cost 
//        Node* min = pq.top();
//
//        // The found node is deleted from the list of 
//        // live nodes 
//        pq.pop();
//
//        // if min is an answer node 
//        if (min->cost == 0)
//        {
//            // print the path from root to destination; 
//            printPath(min);
//            return;
//        }
//
//        // do for each child of min 
//        // max 4 children for a node 
//        for (int i = 0; i < 4; i++)
//        {
//            if (isSafe(min->x + row[i], min->y + col[i]))
//            {
//                // create a child node and calculate 
//                // its cost 
//                Node* child = newNode(min->mat, min->x,
//                    min->y, min->x + row[i],
//                    min->y + col[i],
//                    min->level + 1, min);
//                child->cost = calculateCost(child->mat, final);
//
//                // Add child to list of live nodes 
//                pq.push(child);
//            }
//        }
//    }
//}
//
//// Driver code 
////int main()
////{
////    // Initial configuration 
////    // Value 0 is used for empty space 
////    int initial[N][N] =
////    {
////        {1, 2, 3},
////        {5, 6, 0},
////        {7, 8, 4}
////    };
////
////    // Solvable Final configuration 
////    // Value 0 is used for empty space 
////    int final[N][N] =
////    {
////        {1, 2, 3},
////        {5, 8, 6},
////        {0, 7, 4}
////    };
////
////    // Blank tile coordinates in initial 
////    // configuration 
////    int x = 1, y = 2;
////
////    solve(initial, x, y, final);
////
////    return 0;
////}
//
//
////#include <iostream>
////#include <algorithm>
////#include <string>
////#include <unordered_map>
////#include <unordered_set>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <algorithm>
////#include <array>
////
////using namespace std;
////vector<pair<int, int>> dirs{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
////vector<vector<int>> goal{ {1, 2, 3}, { 4,5,6 }, { 7, 8,0 } };
////vector<vector<int>> v(3, vector<int>(3, 0));
////using pairs = pair<int, pair<int, int>>;
////
////void printcurrentstatus(const vector<vector<int>>& puzzle) {
////    cout << endl;
////    for (int r = 0; r < 3; ++r) {
////        for (int c = 0; c < 3; ++c) {
////            cout << puzzle[r][c] << " ";
////        }
////        cout << endl;
////    }
////}
////
////bool isgoalreached() {
////    return v == goal;
////}
////
////void printsteps(const vector<int>& steps) {
////    // the goal is reached show the steps
////    cout << "steps: " << endl;
////    for (const auto& step : steps) {
////        cout << step << endl;
////    }
////}
////
////bool statealreadyvisited(const vector<vector<int>>& nextstate, const vector<vector<vector<int>>>& knownstates) {
////    for (const auto& state : knownstates) {
////        if (state == nextstate)
////            return true;
////    }
////    return false;
////}
////
////int getmanhattandistance(const vector<vector<int>>& currentpuzzle, int r, int c) {
////    int sum = 0;
////    pair<int, int> desiredidx = { 0,0 };
////    const auto value = currentpuzzle[r][c];
////    for (int row = 0; row < goal.size(); ++row)
////        for (int col = 0; col < goal[0].size(); ++col)
////            if (goal[row][col] == value)
////                desiredidx = { row, col };
////
////    sum += abs(desiredidx.first - r) + abs(desiredidx.second - c);
////    return sum;
////}
////
////void performmoves(int r, int c) {
////    stack<pair<int, int>> q; // {{r, c}, steps}
////    stack<vector<vector<int>>> currentpuzzleq;
////    vector<vector<vector<int>>> knownstates;
////    q.push({ r,c });
////    currentpuzzleq.push(v);
////
////    while (!q.empty()) {
////        auto idx = q.top();
////        auto currentpuzzle = currentpuzzleq.top();
////        q.pop();
////        currentpuzzleq.pop();
////
////        printcurrentstatus(currentpuzzle);
////
////        if (isgoalreached()) {
////            cout << "puzzle solved!" << endl;
////            break;
////        }
////
////        priority_queue <pairs, vector<pairs>, greater<pairs>> pq;
////        // perform possible moves
////        for (const auto dir : dirs) {
////            auto newr = idx.first + dir.first;
////            auto newc = idx.second + dir.second;
////            if (newr >= 0 && newr < v.size()) {
////                if (newc >= 0 && newc < v[0].size()) {
////                    auto manhattandistance = getmanhattandistance(currentpuzzle, newr, newc);
////                    pq.push({ manhattandistance, {newr, newc} });
////                }
////            }
////        }
////
////        while (!pq.empty()) {
////            auto [distance, newidx] = pq.top();
////            pq.pop();
////
////            swap(currentpuzzle[idx.first][idx.second], currentpuzzle[newidx.first][newidx.second]); // swap
////            // chck if we already had this state and if yes don't push it
////            if (!statealreadyvisited(currentpuzzle, knownstates)) {
////                currentpuzzleq.push(currentpuzzle);
////                q.push({ newidx.first, newidx.second });
////                knownstates.push_back(currentpuzzle);
////            }
////            swap(currentpuzzle[idx.first][idx.second], currentpuzzle[newidx.first][newidx.second]); // rewap for further steps
////        }
////    }
////}
////
////void solvepuzzle() {
////    for (int r = 0; r < v.size(); ++r)
////        for (int c = 0; c < v[0].size(); ++c)
////            if (v[r][c] == 0)
////                performmoves(r, c);
////}
////
////int main()
////{
////    for (int r = 0; r < 3; ++r)
////        for (int c = 0; c < 3; ++c)
////            cin >> v[r][c];
////
////    solvepuzzle();
////
////    return 0;
////}