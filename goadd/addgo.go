package main

import(
	"fmt"
	"time"
	"math/rand"
)
func additionADD(a int, b int) int;
func additionLEA(a int, b int) int;
func main(){
	a := 0
	b := 0
	start := time.Now()
	for i := 0; i<1005000; i++{
		a = rand.Int() % 255
		b = rand.Int() % 255
		additionADD(a, b)
	}
	timeADD := time.Since(start)
	start = time.Now()
	for i := 0; i<1005000; i++{
		a = rand.Int() % 255
		b = rand.Int() % 255
		additionLEA(a, b)
	}
	timeLEA := time.Since(start)
	fmt.Printf("%s ADD, %s LEA\n", timeADD, timeLEA)
	fmt.Printf("On your machine, ADD was faster by %f times\n", float64(timeADD)/float64(timeLEA))
}