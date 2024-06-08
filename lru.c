import java.util.*;
class Main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);

        BST<Integer> bst=new BST<>();
        int x,ch;

        do
        {
            System.out.println("enter\n1 for insert\n2 for search\n3 for inorder\n4 for size\nothers exit\n");
            ch=sc.nextInt();
            switch(ch)
            {
                case 1 : System.out.println("enter data to insert");
                            x=sc.nextInt();
                            bst.insert(x); break;

                case 2 : System.out.println("enter data to search");
                            x=sc.nextInt();
                            System.out.println(bst.search(x)); break;
                
                case 3 : System.out.println(bst.size());break;

                case 4 : bst.inorder(); break;

                default : System.exit(0);

            }
        }while(true);
    }
}
class BST<T extends Comparable<T>>
{
	class Node
	{
		T data;
		Node left,right;
		Node(T data)
		{
			this.data=data;left=right=null;
		}	
	}
	
	Node root=null;
    
    void insert(T data)
    {
        root=insert(root,data);
    }

    Node insert(Node root,T data)
    {
            if(root==null)
                return new Node(data);

            if(data.compareTo(root.data)<0)
                root.left=insert(root.left,data);
            else
                root.right=insert(root.right,data);

            return root;
    }

    boolean search(T data)
    {
        return search(root,data);
    }

    boolean search(Node root,T data)
    {
         if(root==null)
                return false;

        if(root.data.equals(data))
            return true;

         if(data.compareTo(root.data)<0)
             return search(root.left,data);
         else
             return search(root.right,data);

    }

    void inorder()
    {
        inorder(root);
    }

    void inorder(Node root)
    {
        while(root!=null)
        {
        inorder(root.left);
        System.out.println(root.data+" ");
        inorder(root.right);
        }
    }

    int size()
    {
        return size(root);
    }

    int size(Node root)
    {
        if(root==null)
            return 0;

        return 1+size(root.left)+size(root.right);
    }

}