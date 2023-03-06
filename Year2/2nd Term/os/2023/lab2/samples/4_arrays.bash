#!/bin/bash
farm_hosts=(web03 web04 web05 web06 web07)
for i in ${farm_hosts[*]}; do
echo item: $i
done
