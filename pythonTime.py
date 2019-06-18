#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
File: pythonTime.py

Author: Max Maleno

Last Updated: 6/4/19

"""

# TODO: comment shit

import time

def getTimeToEvent(eventUnixTime):

    # adapted from https://stackoverflow.com/questions/4048651/python-function-to-convert-seconds-into-minutes-hours-and-days
    intervals = (
        ('days', 86400, 1),    # 60 * 60 * 24
        ('hours', 3600, 2),    # 60 * 60
        ('minutes', 60, 3),
        ('seconds', 1, 4),
        )

    seconds = eventUnixTime-time.time()

    result = []
    # division_output 1 for days, 2 hours, 3 minutes, 4 seconds

    days_output = 0
    hours_output = 0
    minutes_output = 0
    seconds_output = 0

    for name, count, division_output in intervals:
        
        value = seconds // count
    
        if value:
            seconds -= value * count
    
            if value == 1:
                name = name.rstrip('s')
            result.append("{} {}".format(value, name))

        if(division_output == 1): days_output = int(value)
        if(division_output == 2): hours_output = int(value)
        if(division_output == 3): minutes_output = int(value)
        if(division_output == 4): seconds_output = int(value)
    
    complete_string = ', '.join(result)

    print(complete_string)


    print("Days: " + str(days_output))
    print("Hours: " + str(hours_output))
    print("Minutes: " + str(minutes_output))
    print("Seconds: " + str(seconds_output))

    return [days_output, hours_output, minutes_output, seconds_output]

# website to find UNIX time: https://www.epochconverter.com/
print(getTimeToEvent(eventUnixTime = 1567904460))