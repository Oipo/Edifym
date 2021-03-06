import subprocess
import os
from typing import List


class CommandHelper:

    @staticmethod
    def run_command(command: List[str], show_output: bool = True, show_error: bool = True, cwd: str = './EdifymRunner'):
            proc = subprocess.Popen(command, cwd=cwd, env={}, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            if show_output:
                args = ' '.join(proc.args)
                print(f'executing {args}')

            output, error = proc.communicate()

            if show_output and output:
                print(f'{command[0]} output> {proc.returncode} {output}')
            if show_error and error:
                print(f'{command[0]} error> {proc.returncode} {error.strip()}')

    @staticmethod
    def run_command_output(command: List[str], cwd: str = './EdifymRunner') -> str:
            proc = subprocess.Popen(command, cwd=cwd, env={}, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

            output, error = proc.communicate()

            return output

    @staticmethod
    def get_immediate_subdirectories(a_dir: str) -> List[str]:
        dirs = os.listdir(a_dir)
        subdirs = []

        for name in dirs:
            if name == "zstd-dict" or name == "dict.pkl":
                continue
            path = os.path.join(a_dir, name)
            if os.path.isdir(path):
                subdirs.append(name)

        return subdirs