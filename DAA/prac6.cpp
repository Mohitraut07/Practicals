#include <iostream> 
using namespace std;
class Edge
{
public:
    int src, dest, wt;
};
bool compare(Edge e1, Edge e2)
{
    return e1.wt < e2.wt;
}
class KruskalAlgo
{
private:
    int *p, len, v;
    Edge *nodes;

public:
    KruskalAlgo(int l, int nodelens)
    {
        len = l;
        v = nodelens;
        nodes = new Edge[nodelens];
        for (int i = 0; i < nodelens; i++)
        {
            cout << "Enter Source, Destination and Weight : ";
            cin >> nodes[i].src >> nodes[i].dest >> nodes[i].wt;
        }
        p = new int[len];
        for (int i = 0; i < len; i++)
        {
            p[i] = i;
        }
        sort(nodes, nodes + v, compare);
    }
    int findParent(int node)
    {
        if (p[node] == node)
            return node;
        return findParent(p[node]);
    }
    void unionNode(int node1, int node2)
    {
        int pNode1 = findParent(node1);
        int pNode2 = findParent(node2);
        if (pNode1 == pNode2)
            return;
        p[pNode1] = pNode2;
    }
    void run()
    {
        int count = 1, ans = 0;
        for (int i = 0; count < len && i < v; i++)
        {
            Edge nowEdge = nodes[i];
            int psrc = findParent(nowEdge.src);
            int pdest = findParent(nowEdge.dest);
            if (psrc != pdest)
            {
                unionNode(psrc, pdest);
                count++;
                ans += nowEdge.wt;
            }
        }
        cout << "Total Weight : " << ans;
    }
    void printnodes()
    {
        for (int i = 0; i < v; i++)
        {

            cout << nodes[i].wt << endl;
        }
        cout << endl;
    }
};
int main()
{
    KruskalAlgo a = KruskalAlgo(6, 10);
    a.run();
}