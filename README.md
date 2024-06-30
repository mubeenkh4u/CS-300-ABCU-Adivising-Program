## Introduction
The ABCU Advising Program, which provides a powerful and effective tool for improving the advising experience, marks a significant development in academic assistance technology at ABCU. By giving students timely and precise information for their educational journey, we hope to not only increase the advising office's operating efficiency but also positively impact their academic performance. Below is the linked Project Folder to access the Big-O-Runtime Analysis as well as the completed CPP+ program implementing Hash Tables. 
  * [Project Folder]()

## Problem Solving in Projects
The main challenge in this course's projects was to successfully organize and edit course data so that all of the material—including prerequisites—could be effectively saved, retrieved, and updated. In order to decide which data structure would best satisfy the objectives for performance and usability, this included generating and analyzing a variety of data structures.

## Approach to the Problem
The first step in fixing this issue was realizing how crucial data structures are to the creation of software. Because they make it possible to manage massive volumes of data effectively, data structures are essential for optimizing algorithm performance and speed. Three types of data structures were taken into consideration for this project: hash tables, binary search trees (BST), and vectors.

## Overcoming Roadblocks
Managing each data structure's complexity presented a substantial challenge, especially in terms of implementation and efficiency issues. For instance, I encountered difficulties with slow insertion and deletion times when implementing the vector structure. Implementing a hash table raised concerns about how to handle collisions and make sure the hash function works well. The complexity increased since the BST needed to be balanced in order to remain efficient. To ensure a solid grasp and proper implementation, overcoming these challenges required a great deal of testing, troubleshooting, and reviewing theoretical concepts.

## Expansion of Software Design and Development Approach
The project I worked on greatly broadened my perspective on software design and program development. I discovered how crucial it is to select the appropriate data structure depending on the particular requirements of the application. For example, a hash table is ideal if quick lookup speeds are important, but a BST is better if data must be kept in sorted order. This project reaffirmed the need of making deliberate design decisions and taking trade-offs between various data structures into account.

## Evolution of Program Writing
Because of this effort, my programming is now more readable, flexible, and maintainable. I started out concentrating on getting the functionality right, but as the project went on, I realized how important it was to write clear, well-documented code. This entails giving variables meaningful names, segmenting code into digestible functions, and providing comments to clarify intricate reasoning. These techniques facilitate comprehension and modification of the code, which is essential for scalability and long-term maintenance.

## Analysis of Data Structures
  * Vector:
    * Advantages: Simple to implement, dynamic resizing, easy access, and iteration.
    * Disadvantages: Slow insertion/deletion (O(n)), requires contiguous memory.
  * Hash Table:
    * Advantages: Fast insertion, deletion, and search (O(1) on average), handles large data sets well.
    * Disadvantages: Potential for collisions, requires a good hash function, more complex to implement.
  * Binary Search Tree (BST):
    * Advantages: Maintains sorted order, efficient search, insertion, and deletion (O(log n)).
    * Disadvantages: Requires balancing to maintain efficiency, more complex to implement, worst-case O(n) for unbalanced trees.

## Recommendation
For this project, the hash table was suggested since it offers the quickest average time complexity for lookups, insertions, and deletions, making it very effective at managing big datasets. While addressing collisions can be a little complicated, overall usage for direct access is simple. The hash table can be used in conjunction with auxiliary structures if maintaining order is important.

## Conclusion
As I think back on this project, I can see how my methodology has evolved in terms of software design and development. I now recognize how difficult it is to strike a balance between writing maintainable code and selecting the appropriate data structures. I can now design effective and scalable software solutions by making well-informed judgments, which will help me overcome future obstacles.
