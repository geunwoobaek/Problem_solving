Node findSecondLargest(const BST &root, int count)
{
    if(root->right!=nullptr)
    {
        Node biggest = dfs(root); //가장 오른쪽노드 가장 큰노드 찾기..
        //현재찾은노드의 왼쪽 자식이 있을경우는 자식을 리턴
        biggest->left!=nullptr
        return dfs(biggest->left);
        //현재찾은노드의 자식이 없을경우 부모리턴

    }
    else {
        return dfs(root->left)
    }
    
}
Node dfs(root) //가장 오른쪽 노드 찾기
{
    if (root->right == null)
        return root;
    else
        dfs(root->right);
}