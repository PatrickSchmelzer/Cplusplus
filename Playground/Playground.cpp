#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>

using namespace std;

class PuzzleSolver {
public:
	//void readInitialState() {
	//	for (uint8_t r = 0U; r < N; ++r)
	//		for (uint8_t c = 0U; c < N; ++c)
	//			cin >> m_initialState[r][c];

	//	printMatrix(m_initialState);
	//}

	void solve() {
        priority_queue<pair<int, State*>, vector<pair<int, State*>>, greater<pair<int, State*>>> pq;
		const auto [r, c] = getZeroIdx(m_initialState);
		State* start = new State(nullptr, m_initialState, r, c, 0);
		start->cost = calculateCost(m_initialState, m_finalState);
		//pq.push(start);
        pq.push({ start->cost + start->level, start });
		while (!pq.empty()) {
			const auto [complex, state] = pq.top();
			pq.pop();
			if (state->cost == 0) {
				cout << "Result found" << endl;
				return;
			}

			for (const auto [hor, vert] : dirs) {
				int newR = state->zeroIdx.first + hor;
				int newC = state->zeroIdx.second + vert;
				if (newR >= 0 && newR < N && newC >= 0 && newC < N) {
					State* nextState = addState(state, state->matrix, state->zeroIdx.first, state->zeroIdx.second, newR, newC, state->level + 1);
					nextState->cost = calculateCost(nextState->matrix, m_finalState);
                    pq.push({ nextState->cost + nextState->level, nextState });
				}
			}
		}
	}

private:
	static const int N = 3U;
	static inline constexpr array<array<int, N>, N> m_finalState{ { {0, 1, 2}, {3, 4, 5}, {6, 7 ,8} } };
	static inline vector<pair<int,int>> dirs{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	array<array<int,N> , N> m_initialState{ { {6, 1, 8}, {4, 0, 2}, {7, 3 ,5} } };

	struct State {
		State* prevState;
		array<array<int, N>, N> matrix;
		pair<int, int> zeroIdx;
		int cost;
		int level;
		explicit State(State* prevState, const array<array<int, N>, N> matrix, int r, int c, int level) :
			prevState(prevState),
			matrix(matrix),
			level(level),
			cost(INT_MAX) {
			zeroIdx = { r, c };
		}
		
		State() = default;
	};

	pair<int, int> getZeroIdx(const array<array<int, N>, N>& matrix) {
		pair<int, int> zeroIdx = { 0, 0 };
		for (int r = 0; r < N; ++r)
			for (int c = 0; c < N; ++c)
				if (matrix[r][c] == 0)
					zeroIdx = { r, c };
		return zeroIdx;
	}

	State* addState(State* prevState, const array<array<int, N>, N> matrix, int r, int c, int newR, int newC, int level) {
		State* newState = new State;
		newState->prevState = prevState;
		newState->matrix = matrix;
		swap(newState->matrix[r][c], newState->matrix[newR][newC]);
		newState->cost = INT_MAX;
		newState->level = level;
		newState->zeroIdx = { newR, newC };
		return newState;
	}

	int calculateCost(const array<array<int, N>, N>& initial, const array<array<int, N>, N> & final) {
		int count = 0;
		for (int r = 0; r < N; ++r) 
			for (int c = 0; c < N; ++c) 
				if (initial[r][c] && initial[r][c] != final[r][c])
					count += 1;
		return count;
	}


	void printMatrix(const array<array<int, 3>, 3>& m) {
		cout << endl;
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				cout << m[r][c] << " ";
			}
			cout << endl;
		}
	}
};


int main() {
	PuzzleSolver p;
	//p.readInitialState();
	p.solve();
}




#include <iostream>
#include <queue>
using namespace std;
#define N 3 

// state space tree nodes 
struct Node
{
    // stores the parent node of the current node 
    // helps in tracing path when the answer is found 
    Node* parent;

    // stores matrix 
    int mat[N][N];

    // stores blank tile coordinates 
    int x, y;

    // stores the number of misplaced tiles 
    int cost;

    // stores the number of moves so far 
    int level;
};

// Function to print N x N matrix 
void printMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to allocate a new node 
Node* newNode(int mat[N][N], int x, int y, int newX,
    int newY, int level, Node* parent)
{
    Node* node = new Node;

    // set pointer for path to root 
    node->parent = parent;

    // copy data from parent node to current node 
    memcpy(node->mat, mat, sizeof node->mat);

    // move tile by 1 position 
    swap(node->mat[x][y], node->mat[newX][newY]);

    // set number of misplaced tiles 
    node->cost = INT_MAX;

    // set number of moves so far 
    node->level = level;

    // update new blank tile cordinates 
    node->x = newX;
    node->y = newY;

    return node;
}

// botton, left, top, right 
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to calculate the number of misplaced tiles 
// ie. number of non-blank tiles not in their goal position 
int calculateCost(int initial[N][N], int final[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

// Function to check if (x, y) is a valid matrix cordinate 
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// print path from root node to destination node 
void printPath(Node* root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);

    printf("\n");
}

// Comparison object to be used to order the heap 
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

// Function to solve N*N - 1 puzzle algorithm using 
// Branch and Bound. x and y are blank tile coordinates 
// in initial state 
void solve(int initial[N][N], int x, int y,
    int final[N][N])
{
    // Create a priority queue to store live nodes of 
    // search tree; 
    priority_queue<Node*, std::vector<Node*>, comp> pq;

    // create a root node and calculate its cost 
    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);

    // Add root to list of live nodes; 
    pq.push(root);

    // Finds a live node with least cost, 
    // add its childrens to list of live nodes and 
    // finally deletes it from the list. 
    while (!pq.empty())
    {
        // Find a live node with least estimated cost 
        Node* min = pq.top();

        // The found node is deleted from the list of 
        // live nodes 
        pq.pop();

        // if min is an answer node 
        if (min->cost == 0)
        {
            // print the path from root to destination; 
            printPath(min);
            cout << "Number of levels: ";
            cout << min->level << endl;
            return;
        }

        // do for each child of min 
        // max 4 children for a node 
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
                // create a child node and calculate 
                // its cost 
                Node* child = newNode(min->mat, min->x,
                    min->y, min->x + row[i],
                    min->y + col[i],
                    min->level + 1, min);
                child->cost = calculateCost(child->mat, final);

                // Add child to list of live nodes 
                pq.push(child);
            }
        }
    }
}

//// Driver code 
//int main()
//{
//    // Initial configuration 
//    // Value 0 is used for empty space 
//    int initial[N][N] =
//    {
//        {6, 1, 8},
//        {4, 0, 2},
//        {7, 3, 5}
//    };
//
//    // Solvable Final configuration 
//    // Value 0 is used for empty space 
//    int final[N][N] =
//    {
//        {0, 1, 2},
//        {3, 4, 5},
//        {6, 7, 8}
//    };
//
//    // Blank tile coordinates in initial 
//    // configuration 
//    int x = 1, y = 1;
//
//    solve(initial, x, y, final);
//
//    return 0;
//}
