#!/usr/bin/python3
import json, csv, sys
tm = dict(csv.reader(open('team.csv')))
x = json.loads(sys.stdin.read())

for par in x :
    print(tm[par['team_id']], end='\t')
    print(par['rank'], end='\t')
    print(par['score']['num_solved'], par['score']['total_time'], 
        sep='\t', end='\t')
    for prob in par['problems'] :
        if not prob['solved'] : 
            if prob['num_judged'] :
                print('(+{})'.format(prob['num_judged']), end='\t')
            else :
                print('-', end='\t')
        else :
            s = str(prob['time'])
            if prob['num_judged'] > 1:
                s += ' (+{})'.format(prob['num_judged'] - 1)
            print(s, end='\t')
    print()
