### 1766.Tree-of-Coprimes

本题本质就是DFS。当我们考察某个节点curIdx时，在该DFS路径path上的节点就都是它的祖先。我们需要从中找一个深度最大的、与nums[curIdx]互质的节点。理论上我们需要逆序遍历一遍path，但是本题的数据范围限制了所有节点数值不超过50，于是我们可以不遍历节点、而遍历val，来更高效的找到互质的节点。我们只需要在维护path的同时，维护一个hash表records，其中records[d]存储的就是path里所有数值是d的节点的深度。我们在1到50里面寻找与nums[curIdx]互质的d，其中最大的records[d].back()就是离curIdx最近的节点的深度，根据深度从path里面调出那个节点的idx。
