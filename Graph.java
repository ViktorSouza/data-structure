import java.util.*;
public class Graph{
	private int V;
	private int E;
	private ArrayList<HashSet<Integer>> adj;

	public Graph(int V) {
		if (V < 0) throw new IllegalArgumentException("Number of vertices must be non-negative");
		adj = new ArrayList<HashSet<Integer>>(V);
		this.V = V;
		this.E = 0;
		for (int v = 0; v < V; v++) {
			adj.add(null);
			adj.set(v, new HashSet<Integer>());
		}
	}

	    public Graph(Scanner in) {
            this.V = in.nextInt();
            if (V < 0) throw new IllegalArgumentException("number of vertices in a Graph must be non-negative");
				adj = new ArrayList<HashSet<Integer>>(V);
            for (int v = 0; v < V; v++) {
                adj.set(v, new HashSet<Integer>());
            }
            int E = in.nextInt();
            if (E < 0) throw new IllegalArgumentException("number of edges in a Graph must be non-negative");
            for (int i = 0; i < E; i++) {
                int v = in.nextInt();
                int w = in.nextInt();
                addEdge(v, w);
            }
    }
	public HashSet<Integer> adj(int v){
		return adj.get(v);
	}
	public void addEdge(int u, int v){
		adj.get(u).add(v);
		adj.get(v).add(u);
	}
	
	public static void DFS(Graph G, int u){
	}

	public String toString(){
		StringBuilder s = new StringBuilder();
		s.append(V + " vertices and " + E+ " edges\n");
		for(int v = 0; v < V; v++){
			s.append(v+ ": ");
			for (int e:adj.get(v)){
				s.append(e+" ");
			}
			s.append("\n");
		}
		return s.toString();
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		Graph graph = new Graph(10);
		graph.addEdge(0,1);
		graph.addEdge(0,2);
		graph.addEdge(3,2);
		graph.addEdge(5,3);
		graph.addEdge(9,3);
		for (int v: graph.adj(2)){
			System.out.println(v);
		}
		System.out.println(graph);
	}
}
