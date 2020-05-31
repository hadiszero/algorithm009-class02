# 学习笔记 Week02

# 1. Hash Table (HashMap, HashSet)：
## Map：
key不重复 key - value

## Set：
不重复元素的集合. HashSet底层实现是基于HashMap的, 只不过只存放key，不存放value


# 2.树、二叉树、二叉搜索树的实现和特性：
树的结构用于满足人类需求，例如递归树，状态树，决策树.
二叉树的遍历，前序，中序，后续(相对于根的位置)
树的循环比较麻烦，递归是更好的实现.
LinkedList是特殊化的Tree


## 二叉树遍历：Pre-order/In-order/Post-order
前序（Pre-Order）:根 - 左 - 右

中序（In-Order）: 左- 根 - 右

后序（Post-Order）: 左 - 右 - 根

代码实现

```
def preOrder(self, root):
  if root:
      self.traverse_path.append(root.val)
      self.preOrder(root.left)
      self.preOrder(root.right)

def inOrder(self, root):
  if root:
      self.inOrder(root.left)
      self.traverse_path.append(root.val)
      self.inOrder(root.right)

def postOrder(self, root):
  if root:
      self.postOrder(root.left)
      self.postOrder(root.right)
      self.traverse_path.append(root.val)
```


## 二叉搜索树:
空树也是二叉搜索树
左子树的所有节点都小于根
右子树的所有节点都大于根
依次类推，也就是重复性来源 二叉搜索树 Demo，https://visualgo.net/zh/bst


### 常见操作
#### 查询: 
O(log n)

#### 插入: 
O(log n)

#### 删除: 
O(log n): 如果是叶子节点，直接删除，如果不是，则找第一个大于待删除节点来替换掉要删除的节点.


# 3.堆（Heap）、二叉堆(Binary Heap)和图(Graph)：

## Heap:
可以迅速找到一堆数中的最大或者最小值的数据结构.根节点最大的堆叫大顶堆或大根堆、根节点最小 - 小根堆、小顶堆.常见的有二叉堆、斐波那契堆.


### 大顶堆：
find-max: O(1) delete-max : O(logn) insert: O(logn) or O(1)


### 二叉堆：
通过完全二叉树实现（注意：不是二叉搜索树）
​二叉堆实现细节：

二叉堆一般都通过“数组”来实现
假设“第一个元素”在数组中的索引为0的话，则父节点和子节点的位置关系如下：
索引为i的左孩子的索引是（2*i+1）
索引为i的右孩子的索引是（2*i+2）
索引为i的父节点的索引是 floor（（i-1）/2）
