import _vfs from "./wrap.cjs"

export const VFS = _vfs as {
    foo: "bar",
    echo: (str: string) => string,
    createFile: () => string
}