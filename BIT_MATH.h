/* 
 * File:   BIT_MATH.h
 * Author: Owner
 *
 * Created on April 18, 2026, 10:35 AM
 */

#ifndef BIT_MATH_H
#define	BIT_MATH_H


#define SET_BIT(var,BIT) (var|=(1<<BIT))
#define CLR_BIT(var,BIT) (var&=(~(1<<BIT)))
#define TOGGLE_BIT(var,BIT) (var^=(1<<BIT)) 
#define GET_BIT(VAR,BIT) ((VAR>>BIT)&1)

#endif





