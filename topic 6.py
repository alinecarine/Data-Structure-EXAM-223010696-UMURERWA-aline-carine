print('Topic 6')
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def display(self, level=0):
        print(" " * level * 2 + str(self.data))
        for child in self.children:
            child.display(level + 1)

# Example usage
root = TreeNode("Skincare")
child1 = TreeNode("Moisturizers")
child2 = TreeNode("Cleansers")
child3 = TreeNode("Sunscreens")
root.add_child(child1)
root.add_child(child2)
root.add_child(child3)
child1.add_child(TreeNode("skincare"))
child1.add_child(TreeNode("cleanser"))
root.display()
