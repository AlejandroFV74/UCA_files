export const createAuthorController = async (req, res, next) => {
    try {
        const author = req.body;
        const existAuthor = await findAuthorByNameAndLastName(author.name, author.lastName);
        if (existAuthor) throw createError(400, 'El autor ya existe');
        const authorCreated = await saveAuthor(author);
        res.status(201).json({ message: 'author created', data: authorCreated });
    } catch (e) {
        switch (e.code) {
            case AuthorErrorCodes.AUTHOR_NOT_FOUND:
                next(createError(404, 'El autor no existe'));
                break;
            case AuthorErrorCodes.AUTHOR_SEARCH_FAILED:
                next(createError(500, 'Error al buscar el autor'));
                break;
            default:
                next(e);
        }
    }
}