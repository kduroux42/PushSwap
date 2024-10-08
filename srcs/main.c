/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:39 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/02 16:35:01 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

char *argv_to_str(char **av, char **stockage) {
  int i;

  i = 1;
  while (av[i]) {
    if (!av[i][0]) {
      free(*stockage);
      exit(2);
    }
    *stockage = ft_strjoin(*stockage, av[i]);
    *stockage = ft_strjoin(*stockage, " ");
    i++;
  }
  return (*stockage);
}

void free_split(char **str) {
  int i;

  i = 0;
  while (str[i]) {
    free(str[i]);
    i++;
  }
  free(str);
}

int is_valid(char *str) {
  int i;
  int j;
  char **res;

  res = ft_split(str, ' ');
  i = 0;
  while (res[i]) {
    j = 0;
    while (res[i][j]) {
      if (!(res[i][j] >= '0' && res[i][j] <= '9')) {
        free_split(res);
        return (0);
      }
      j++;
    }
    i++;
  }
  free_split(res);
  return (1);
}

int is_doublon(char *str) {
  int i;
  int j;
  int len;
  char **res;

  i = 0;
  res = ft_split(str, ' ');
  while (res[i]) {
    j = 1 + i;
    while (res[j]) {
      len = ft_strlen(res[i]);
      if (res[j] > res[i])
        len = ft_strlen(res[j]);
      if (ft_strncmp(res[i], res[j], len) == 0) {
        free_split(res);
        return (1);
      }
      j++;
    }
    i++;
  }
  free_split(res);
  return (0);
}

int main(int ac, char **av) {
  char *test;

  if (ac >= 2) {
    test = NULL;
    test = argv_to_str(av, &test);
    if (!is_valid(test) || is_doublon(test))
      printf("fail");
    free(test);
  }
  return (0);
}
