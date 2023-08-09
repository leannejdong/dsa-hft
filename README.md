# Data structures and Algorithms for low latency applications

## Data structures

* list, binary tree, tries, priority queues, hash tables, arrays

## Algorithms

* sorting (quicksort, radix), binary search

* optimized networking protocols for faster data transmission

 ## Example

###  Order book Optimization

Suppose you are given an order book for a low latency trading system. The order book needs o efficiently handle incoming buy and sell orders and provide quick access to the best bid
and the best ask prices. Implement

1 `add_order(order_id, price, quantity, is_buy)`: Adds a new order with the given `order_id`, price, quantity, and whether it is a buy (`is_buy = True`) or sell (`is_buy_False`) order.

2. `cancel_order(order_id)`: cancels the order with the specified `order_id`

3. `get_best_bid()`: returns the best bid price and quantity

4. `get_best_ask()`: returns the best ask price and quantity

* Assumptions:

  - Orders with the same price are first come first served
  - when an oder added, if it matches an existing opposite-type order at the same or better price,
  - a trade occurs and the order with the smaller quantity is removed
 
Your task is to implement the above function in a way that minimizes the time complexity and maximizes the efficiency of order book operation.

* Design the program first

  - Choose the data structure
  - Adding Orders
  - Cancelling Orders
  - Getting Best Bid and Best Ask
  - Time complexity
  - Trade execution
 
By using binary heaps (priority queues) for buying and selling orders, along with a hash table for efficient order tracking, this design ensure the order book operations are performed with low time complexity.
The structure is optimized for quickly retrieving the best bid and best ask prices, while efficiently handling trades and cencellaions.

https://godbolt.org/z/MMWWPWKzM
 


  



