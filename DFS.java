import java.util.*;
public class DFS{

	public boolean[] marked;
	public int[] predecessor;
	public ArrayList<Integer> postorder;
	private int count;

	public DFS(Graph G, int s){
		marked = new boolean[G.V()];
		predecessor = new int[G.V()];
		postorder = new ArrayList<Integer>(G.V());
		dfs(G,s);
	}

	private void dfs(Graph g, int v){
		count++;
		marked[v] = true;
		for(int u: g.adj(v)){
			predecessor[u] = v;
			if(!marked[u])
				dfs(g,u);
		}
		postorder.add(v);
	}


	public boolean marked(int v){
		return marked[v];
	}
	public int count(){
		return count;
	}

}
