#!/usr/bin/python3

def parsePOSIX(args: list):
    IsOptsAllowed = True

    i = 0
    while i != len(args):
        # End of options marker?
        if args[i] == "--":
            IsOptsAllowed = False
            i += 1
            continue

        # Option?
        if IsOptsAllowed and args[i][0] == '-' and len(args[i]) > 1:
            # Option
            if len(args[i]) == 2:
                # Just option
                # Для примера условимся, что все опции имеют аргумент
                # тем более, что POSIX добровольно-принуждает к этому
                print(f'{args[i]}: optional')
                # print(f'  value = {args[i + 1]}')
                # i += 1
            else:
                # Combination
                combo = []
                for j in range(1, len(args[i])):
                    combo.append(f'-{args[i][j]}')
                parsePOSIX(combo)
            i += 1
            continue

        # Positional arg
        print(f'{args[i]}: positional')
        i += 1

if __name__ == '__main__':
    parsePOSIX([
        'p1',
        '-f',
        '-xyz',
        '--',
        '-f', 'true'
    ])
